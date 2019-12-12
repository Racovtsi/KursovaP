//---------------------------------------------------------------------------
#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

  TComponentList *DImageList; //список дин. имейджов
  AnsiString spinName;
  TImage* img;
  int i = 0, left = -10, top = 320, temp = 0, temp1 = 0;
  const int AR[9] = {1,1,1,1,1,1,1,1,1};
  const int KR[18] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  bool ar = false;
  bool kr = false;
  bool view = true;


  std::vector<int>winSpin;
  std::vector<int>trueSpin;

 //функція створює на формі зображення вибраного спіна(1,2,3)
void __fastcall TForm2::Spin(int spin){

 switch(spin){
  case 1 :
  {
   spinName = "updown";
   if(!(i == 16))
	trueSpin.push_back(1);
  }
  break;
  case 2 :
  {
   spinName = "up";
   if(!(i == 16))
	trueSpin.push_back(2);
  }
  break;
  case 3 :
  {
   spinName = "down";
   if(!(i == 16))
	trueSpin.push_back(3);
  }
  break;
  case 4 :  //Добавление Ar
  {
  if(i == 0)
   {
	spinName = "ar";
	ar = true;
	for(int j = 0; j<9; j++)
	trueSpin.push_back(AR[j]);
   }
  else
   {
  ShowMessage("\"Ar\" можна додати тільки на початку");
  view = false;
   }
  }
  break;
  case 5 : //Добавление Kr
  {
  if(i == 0)
   {
	spinName = "kr";
	kr = true;
	for(int j = 0; j<18; j++)
	trueSpin.push_back(KR[j]);
   }
  else
   {
  ShowMessage("\"Kr\" можна додати тільки на початку");
  view = false;
   }
  }
  break;
  case 6 :  //Удаление имейдж компонента
  {
  if(ar == true && i == 1)
   {
	for(int j = 0; j<9; j++)
	 trueSpin.pop_back();
	 ar = false;
   }
  else if(kr == true && i == 1)
   {
	for(int j = 0; j<18; j++)
	 trueSpin.pop_back();
	 kr = false;
   }
  else
   trueSpin.pop_back();
   view = false;

   if(!DImageList->Count==0)
   {
	DImageList->Delete(DImageList->Count-1);
	i--;


   if(ar == true || kr == true)
	 {
	  if(i == 1 || i == 2 || i == 7 || i == 10 || i == 11)
	  top +=25;
	 }
   else
	 {
	  if(i == 1 || i == 2 || i == 5 || i == 6 || i == 9 || i == 10 || i == 15)
	  top +=25;
	 }
   left -=35;
   }
  }
  break;
  case 7 :  //Проверка на правильно введенные спины
  {
   view = false;
   if(trueSpin == winSpin) //winSpin берет из Form1
   ShowMessage(L"    ВIРНО ツ");
   else
   ShowMessage(L"    невірно");
  }
  break;
 }

if(view == true) //Создание имейдж компонент
 {
  if(i == 16)
   {
   if(ar == true)
	ShowMessage("Занадто багато спiнiв, замість цього використовуй \"Kr\" на початку");
   else if(kr == true)
	ShowMessage("Занадто багато спiнiв");
   else
	ShowMessage("Занадто багато спiнiв, замість цього використовуй \"Ar\" на початку");
   }
  else
   {
	if(ar == true || kr == true)
	{
	if(i == 1 || i == 2 || i == 7 || i == 10 || i == 11)
	top -=25;
	}
	else
	{
	if(i == 1 || i == 2 || i == 5 || i == 6 || i == 9 || i == 10 || i == 15)
	top -=25;
	}
   left +=35;

   img = new TImage(Form2);
   DImageList->Add(img);
   img->Parent = Form2;
   img->Left = left;
   img->Top = top;
   img->Width = Form2->ClientWidth - 10 - 20;
   img->Visible = true;
   img->Picture->LoadFromFile("Picture/spin/"+spinName+".bmp");
   i++;
   }
 }
else
 {
  view = true;
 }
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{ //Очищает и закрывает форму
for(int j = 0; j<temp; j++)
{
 if(!DImageList->Count==0)
 {
	DImageList->Delete(DImageList->Count-1);
	i--;
	if(ar == true || kr == true)
	 {
	  if(i == 1 || i == 2 || i == 7 || i == 10 || i == 11)
	  top +=25;
	 }
	else
	 {
	  if(i == 1 || i == 2 || i == 5 || i == 6 || i == 9 || i == 10 || i == 15)
	  top +=25;
	 }
	left -=35;
   }
}
trueSpin.clear();
winSpin.clear();
temp = 0;
i = 0;
Form2->Close();
//Form2->ClientWidth = 675;
Form1->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{ //Очищает и закрывает форму
for(int j = 0; j<temp; j++)
{
 if(!DImageList->Count==0)
 {
  DImageList->Delete(DImageList->Count-1);
  i--;
  if(ar == true || kr == true)
   {
	if(i == 1 || i == 2 || i == 7 || i == 10 || i == 11)
	top +=25;
   }
  else
   {
	if(i == 1 || i == 2 || i == 5 || i == 6 || i == 9 || i == 10 || i == 15)
	top +=25;
   }
  left -=35;
 }
}
trueSpin.clear();
winSpin.clear();
temp = 0;
i = 0;
//Form2->ClientWidth = 675;
Form1->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
Spin(1); //updown
temp++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton2Click(TObject *Sender)
{
Spin(2); //up
temp++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton3Click(TObject *Sender)
{
Spin(3); //down
temp++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
Spin(6); //Очистить
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
DImageList = new TComponentList; // создаем список
DImageList->OwnsObjects = true;
Application->Title = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
Spin(7); //Проверить
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton4Click(TObject *Sender)
{
Spin(4); //Ar
temp++;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
if(Form2->Label1->Width < 735)
 {
  Panel3->Left = 130;
  Panel4->Left = 257;
  Panel5->Left = 441;
  SpeedButton6->Left = 620;
  Form2->ClientWidth = 680;
 }
else
 {
 switch(Form2->Label1->Width)
  {
  case 735 :
   {
	Panel3->Left = 150;
	Panel4->Left = 277;
	Panel5->Left = 461;
	SpeedButton6->Left = 710;
	Form2->ClientWidth = 770;
   break;
   }

  case 823 :
   {
	Panel3->Left = 190;
	Panel4->Left = 317;
	Panel5->Left = 501;
	SpeedButton6->Left = 798;
	Form2->ClientWidth = 858;
   break;
   }

  case 916 :
   {
	Panel3->Left = 230;
	Panel4->Left = 357;
	Panel5->Left = 541;
	SpeedButton6->Left = 891;
	Form2->ClientWidth = 951;
   break;
   }

  case 940 :
   {
	Panel3->Left = 250;
	Panel4->Left = 367;
	Panel5->Left = 559;
	SpeedButton6->Left = 915;
	Form2->ClientWidth = 975;
   break;
   }

  case 1033 :
   {
	Panel3->Left = 290;
	Panel4->Left = 417;
	Panel5->Left = 601;
	SpeedButton6->Left = 1008;
	Form2->ClientWidth = 1068;
   break;
   }
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton5Click(TObject *Sender)
{
Spin(5);
temp++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton6Click(TObject *Sender)
{
ShowMessage(L"Виконав Раковцi Йосип 41-К  ( ˇ෴ˇ )");
}
//---------------------------------------------------------------------------


