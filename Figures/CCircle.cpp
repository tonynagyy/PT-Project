#include "CCircle.h"
#include <cmath>

//int CCircle::Count = 0;

 CCircle::CCircle(const Point &p1, const Point &p2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo), P1(p1), P2(p2)
 {
	 
	 Identifier = 5;
	 Count++;
	 ID = Count;
 }
 void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	 pOut->DrawCircle(P1, P2, FigGfxInfo, Selected);
}

 bool CCircle::InFigure(int x, int y)
 {
	 // Check if the point is in or not by comparing the radius with distance between the point and the center 
	 return (DEST(P1.x, P1.y, x, y) < DEST(P1.x, P1.y, P2.x, P2.y));
 }

 /*
 int CCircle::Counter()
 {
	 return Count;
 }
 */
 void CCircle::FakeDraw(Output* pOut)
 {
	 FigGfxInfo.DrawClr = LIGHTGOLDENRODYELLOW;
	 Draw(pOut);
	 FigGfxInfo.DrawClr = BLUE;
 }

 double CCircle::CalcArea()
 {
	 // Calculate the area of the circle 
	 double r = CIRCLE_RADIUS(DELTA(P1.x, P2.x), DELTA(P1.y, P2.y));
	 return PI * r * r;
 }

 int CCircle::GetID()
 {
	 return ID;
 }

 /*
 int CCircle::GetNum()
 {
	 return Num;
 }

 void CCircle::DecNum()
 {
	 Num--;
 }

 void CCircle::IncNum()
 {
	 Num++;
 }
 */

 Point CCircle::Getcenter()
 {
	 return P1;
 }

 color CCircle::GetDrawClr()
 {
	 return FigGfxInfo.DrawClr;
 }

 color CCircle::GetFillClr()
 {
	 return FigGfxInfo.FillClr;
 }

 void CCircle::PrintInfo(Output* pOut)
 {
	 string msg;

	 string S = "Circle ID: ";
	 string S1 = "  Figure: Circle    Area: ";
	 string S2 = "  Center: (";
	 string S3 = " , ";
	 string S4 = ")   Is Filled :  ";
	 string S5 = " False";
	 string S6 = " True";
	 if (FigGfxInfo.isFilled)
	 {
		 string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string(P1.x) + S3 + to_string(P1.y) + S4 + S6;
		 pOut->PrintMessage(msg);
	 }
	 else
	 {
		 string msg = S + to_string(ID) + S1 + to_string(CalcArea()) + S2 + to_string(P1.x) + S3 + to_string(P1.y) + S4 + S5;
		 pOut->PrintMessage(msg);
	 }
 }


 CFigure* CCircle::clone() const
 {
	 return new CCircle(*this);
 }

 void CCircle::Save(ofstream& OutFile)
 {
	 OutFile << "CIRC\t" << ID << "\t";
	 OutFile << P1.x << "\t" << P1.y << "\t" << P2.x << "\t" << P2.y << "\t";
	 OutFile << FigGfxInfo.DrawClr << "\t";
	 OutFile << FigGfxInfo.FillClr << endl;
 }

 void CCircle::Load(ifstream& inFile) {
	 inFile >> ID >> P1.x >> P1.y >> P2.x >> P2.y;
	 inFile >> FigGfxInfo.DrawClr;
	 inFile >> FigGfxInfo.FillClr;
 }

 void CCircle::move(double x, double y)
 {
	 
      double shiftx = x - P1.x;
	 double shifty = y - P1.y;
	 P1.x = x;
	 P2.x = P2.x +shiftx;
	 P1.y = y;
	 P2.y = P2.y +shifty;

 }

 


