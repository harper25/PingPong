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
    TImage *ball;
    TTimer *timerBall;
    TButton *buttonNewGame;
    TShape *score;
    TLabel *points;
    TRadioGroup *RadioGroup1;
    TRadioButton *RadioButton4;
    TRadioButton *RadioButton7;
    TRadioButton *RadioButton11;
    TRadioButton *RadioButton21;
    TLabel *winner;
    TEdit *player1;
    TEdit *player2;
    TLabel *player1static;
    TLabel *player2static;
    void __fastcall timerLPupTimer(TObject *Sender);
    void __fastcall timerLPdownTimer(TObject *Sender);
    void __fastcall timerRPupTimer(TObject *Sender);
    void __fastcall timerRPdownTimer(TObject *Sender);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall timerBallTimer(TObject *Sender);
    void __fastcall buttonNewGameClick(TObject *Sender);
    void __fastcall RadioButton4Click(TObject *Sender);
    void __fastcall RadioButton7Click(TObject *Sender);
    void __fastcall RadioButton11Click(TObject *Sender);
    void __fastcall RadioButton21Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TGameWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGameWindow *GameWindow;
//---------------------------------------------------------------------------
#endif
