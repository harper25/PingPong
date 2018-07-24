//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGameWindow *GameWindow;
//---------------------------------------------------------------------------
__fastcall TGameWindow::TGameWindow(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGameWindow::timerLPupTimer(TObject *Sender)
{
    if (leftpaddle->Top > 10) leftpaddle->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::timerLPdownTimer(TObject *Sender)
{
    if (leftpaddle->Top + leftpaddle->Height < background->Height - 10) leftpaddle->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::timerRPupTimer(TObject *Sender)
{
    if (rightpaddle->Top > 10) rightpaddle->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TGameWindow::timerRPdownTimer(TObject *Sender)
{
    if (rightpaddle->Top + rightpaddle->Height < background->Height - 10) rightpaddle->Top += 10;
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


