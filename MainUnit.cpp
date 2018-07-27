//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGameWindow *GameWindow;

randomize();
int ballVelocity;
int ballRotation;
int ballDirectionLeftRight;
int x;
int y;
int numberOfSuccessfulBounces = 0;
int pointsPlayer1, pointsPlayer2;
int pointsToWin = 4;

void setNewGameLayout()
{
    GameWindow->RadioGroup1->Visible = true;
    GameWindow->RadioButton4->Visible = true;
    GameWindow->RadioButton7->Visible = true;
    GameWindow->RadioButton11->Visible = true;
    GameWindow->RadioButton21->Visible = true;
    GameWindow->buttonNewGame->Visible = true;

    GameWindow->player1static->Visible = false;
    GameWindow->player2static->Visible = false;
    GameWindow->player1->Visible = true;
    GameWindow->player2->Visible = true;

    GameWindow->points->Caption = "0:0";
}

void setNewRoundLayout()
{
    GameWindow->ball->Left = 392;
    GameWindow->ball->Top = 220;
    numberOfSuccessfulBounces = 0;
    GameWindow->ball->Visible = true;

    ballVelocity = 6;
    ballRotation = random(91) - 45;
    ballDirectionLeftRight = random(2);
    x = ballVelocity * cos((double) 3.14/180.0 * ballRotation);
    y = ballVelocity * sin((double) 3.14/180.0 * ballRotation);
    if (ballDirectionLeftRight == 1)
        x = -x;

    GameWindow->buttonNewGame->Visible = false;
    GameWindow->timerBall->Enabled = true;
}

//---------------------------------------------------------------------------
__fastcall TGameWindow::TGameWindow(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TGameWindow::timerLPupTimer(TObject *Sender)
{
    if (leftpaddle->Top > score->Height + 10) leftpaddle->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::timerLPdownTimer(TObject *Sender)
{
    if (leftpaddle->Top + leftpaddle->Height <
        score->Height + background->Height - 10) leftpaddle->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::timerRPupTimer(TObject *Sender)
{
    if (rightpaddle->Top > score->Height + 10) rightpaddle->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::timerRPdownTimer(TObject *Sender)
{
    if (rightpaddle->Top + rightpaddle->Height <
        score->Height + background->Height - 10) rightpaddle->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP) timerRPup->Enabled = true;
    if (Key == VK_DOWN) timerRPdown->Enabled = true;
    if (Key == 'A') timerLPup->Enabled = true;
    if (Key == 'Z') timerLPdown->Enabled = true;
    if (Key == 'P')
    {
        if (timerBall->Enabled == true)
            {
                timerBall->Enabled = false;
            }
        else
            {
                timerBall->Enabled = true;
            }
    }
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP) timerRPup->Enabled = false;
    if (Key == VK_DOWN) timerRPdown->Enabled = false;
    if (Key == 'A') timerLPup->Enabled = false;
    if (Key == 'Z') timerLPdown->Enabled = false;
}


void __fastcall TGameWindow::timerBallTimer(TObject *Sender)
{
    ball->Left += x;
    ball->Top += y;

    // bounce from top and bottom wall
    if (ball->Top-5 <= background->Top)       y = -y;
    if (ball->Top + ball->Height+5 >= background->Height + score->Height)
        y = -y;

    // point for player1
    if (ball->Left <= background->Left)
    {
        timerBall->Enabled = false;
        ball->Visible = false;
        pointsPlayer2++;

        points->Caption = IntToStr(pointsPlayer1) + ":" + IntToStr(pointsPlayer2);

        if (pointsPlayer2 >= pointsToWin)
        {

            winner->Caption = "The winner is " + player2->Text + "!";
            winner->Visible = true;
            setNewGameLayout();
        }
        else
        {
            Application->ProcessMessages();
            Sleep(1000);
            setNewRoundLayout();
        }
    }
    // point for player2
    else if (ball->Left + ball->Width >= background->Left + background->Width)
    {
        timerBall->Enabled = false;
        ball->Visible = false;
        pointsPlayer1++;

        points->Caption = IntToStr(pointsPlayer1) + ":" + IntToStr(pointsPlayer2);

        if (pointsPlayer1 >= pointsToWin)
        {
            winner->Caption = "The winner is " + player1->Text + "!";
            winner->Visible = true;
            setNewGameLayout();
        }
        else
        {
            Application->ProcessMessages();
            Sleep(1000);
            setNewRoundLayout();
        }
    }
    // bounce from left paddle
    else if (ball->Top + ball->Height/2 >= leftpaddle->Top &&
             ball->Top + ball->Height <= leftpaddle->Top + leftpaddle->Height + ball->Height/2 &&
             ball->Left < leftpaddle->Left + leftpaddle->Width)
    {
        numberOfSuccessfulBounces++;
        if (numberOfSuccessfulBounces%5 == 0)   ballVelocity++;
        if (x < 0)
        {
            float partOfPaddle = -(((float) leftpaddle->Top + leftpaddle->Height/2) -
                ((float) ball->Top + ball->Height/2))/ ((float) leftpaddle->Height/2);

            ballRotation = (int) 60 * partOfPaddle;

            if (ballRotation > 45) ballRotation = 45;
            if (ballRotation < -45) ballRotation = -45;
            x = ballVelocity * cos(3.14/180.0 * (double) ballRotation);
            y = ballVelocity * sin(3.14/180.0 * (double) ballRotation);
        }
    }
    // bounce from right paddle
    else if (ball->Top + ball->Height/2 >= rightpaddle->Top &&
             ball->Top + ball->Height <= rightpaddle->Top + rightpaddle->Height + ball->Height/2 &&
             ball->Left + ball->Width > rightpaddle->Left)
    {
        numberOfSuccessfulBounces++;
        if (numberOfSuccessfulBounces%5 == 0)   ballVelocity++;
        if (x > 0)
        {
            float partOfPaddle = -(((float) rightpaddle->Top + rightpaddle->Height/2) -
                ((float) ball->Top + ball->Height/2))/ ((float) rightpaddle->Height/2);

            //ballRotation = - ballRotation + (int) 60 * partOfPaddle;
            ballRotation = (int) 60 * partOfPaddle;

            if (ballRotation > 45) ballRotation = 45;
            if (ballRotation < -45) ballRotation = -45;
            x = - ballVelocity * cos(3.14/180.0 * (double) ballRotation);
            y = ballVelocity * sin(3.14/180.0 * (double) ballRotation);
        }
    }

}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::buttonNewGameClick(TObject *Sender)
{
    ball->Left = 392;
    ball->Top = 220;
    numberOfSuccessfulBounces = 0;
    pointsPlayer1 = 0;
    pointsPlayer2 = 0;
    ball->Visible = true;
    RadioGroup1->Visible = false;
    RadioButton4->Visible = false;
    RadioButton7->Visible = false;
    RadioButton11->Visible = false;
    RadioButton21->Visible = false;
    winner->Visible = false;

    player1static->Caption = player1->Text;
    player2static->Caption = player2->Text;
    player1static->Visible = true;
    player2static->Visible = true;
    player1->Visible = false;
    player2->Visible = false;

    ballVelocity = 6;
    ballRotation = random(91) - 45;
    ballDirectionLeftRight = random(2);
    x = ballVelocity * cos((double) 3.14/180.0 * ballRotation);
    y = ballVelocity * sin((double) 3.14/180.0 * ballRotation);
    if (ballDirectionLeftRight == 1)
        x = -x;

    buttonNewGame->Visible = false;
    timerBall->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::RadioButton4Click(TObject *Sender)
{
    pointsToWin = 4;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::RadioButton7Click(TObject *Sender)
{
    pointsToWin = 7;    
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::RadioButton11Click(TObject *Sender)
{
     pointsToWin = 11;        
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::RadioButton21Click(TObject *Sender)
{
    pointsToWin = 21;        
}
//---------------------------------------------------------------------------


void __fastcall TGameWindow::FormActivate(TObject *Sender)
{
    Application->MessageBox(
        "Welcome to Ping Pong!                                           \n\n"
        "Controls of Player 1:\n"
        "A - move up\n"
        "Z - move down\n\n"
        "Controls of Player 2:\n"
        "<arrow_up> - move up\n"
        "<arrow_down> - move down\n\n"
        "Additional info:\n"
        "1. The ball moves faster with the passing of time.\n"
        "2. It is possible to write players names before beginning\n"
        "    of the game.\n"
        "3. Press 'P' to pause/resume the game\n\n"
        "Enjoy!",
        "Ping Pong", MB_OK);
    GameWindow->Visible = true;
    GameWindow->BringToFront();    
}
//---------------------------------------------------------------------------





