//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TGameWindow : public TForm
{
__published:	// IDE-managed Components
    TShape *background;
    TImage *leftpaddle;
    TImage *rightpaddle;
    TTimer *timerLPup;
    TTimer *timerRPup;
    TTimer *timerLPdown;
    TTimer *timerRPdown;
    void __fastcall timerLPupTimer(TObject *Sender);
    void __fastcall timerLPdownTimer(TObject *Sender);
    void __fastcall timerRPupTimer(TObject *Sender);
    void __fastcall timerRPdownTimer(TObject *Sender);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    __fastcall TGameWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGameWindow *GameWindow;
//---------------------------------------------------------------------------
#endif
