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
    if (ball->Top + ball->Height+5 >= background->Height)     y = -y;

    // failure
    if (ball->Left <= background->Left)
    {
        timerBall->Enabled = false;
        ball->Visible = false;
        buttonNewGame->Caption = "The winner is Player 2! Once more?";
        buttonNewGame->Visible = true;
    }
    else if (ball->Left + ball->Width >= background->Left + background->Width)
    {
        timerBall->Enabled = false;
        ball->Visible = false;
        buttonNewGame->Caption = "The winner is Player 1! Once more?";
        buttonNewGame->Visible = true;
    }
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

            //ballRotation = - ballRotation + (int) 60 * partOfPaddle;
            ballRotation = (int) 60 * partOfPaddle;

            if (ballRotation > 45) ballRotation = 45;
            if (ballRotation < -45) ballRotation = -45;
            x = ballVelocity * cos(3.14/180.0 * (double) ballRotation);
            y = ballVelocity * sin(3.14/180.0 * (double) ballRotation);
        }
    }
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
    ball->Visible = true;

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

