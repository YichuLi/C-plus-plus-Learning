#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

const double pi = 3.1416;

class CShape
{
    public:
        virtual double Area() = 0;   // pure virtual function
        virtual void PrintInfo() = 0;
};

class CRectangle:public CShape
{
    public:
        int w,h;    // member var
        virtual double Area();
        virtual void PrintInfo();
};

class CCircle:public CShape
{
    public:
        int r;
        virtual double Area();
        virtual void PrintInfo();
};

class Ctriangle:public CShape
{
    public:
        int a,b,c;
        virtual double Area();
        virtual void PrintInfo();
};

double CRectangle::Area(){
    return w*h;
}

void CRectangle::PrintInfo(){
    cout<< "Rectangle:" << Area() << endl;
}

double CCircle::Area(){
    return  pi * r * r;
}

// I have omit some functions
CShape* pShapes[100];
int MyCompare(const void *s1, const void *s2);

int main()
{
    int i, n;
    CRectangle* pr;
    CCircle* pc;
    Ctriangle* pt;
    cin >> n;
    for(i = 0; i < n; i++){
        char c;
        cin >> c;
        switch(c){
            case 'R':
                pr = new CRectangle();
                cin >> pr->w >> pr->h;
                pShapes[i] = pr;
                break;
            case 'C':
                pc = new CCircle();
                cin >> pc->r;
                pShapes[i] = pc;
                break;
            case 'T':
                pt = new Ctriangle();
                cin >> pt->a >> pt->b >> pt->c;
                pShapes[i] = pt;
        }
    }

    qsort(pShapes, n, sizeof(CShape*), MyCompare);
    for(i = 0; i < n; i++){
        pShapes[i]->PrintInfo();
    }
    return 0;
}

int MyCompare(const void* s1, const void* s2)
{
    double a1, a2;
    CShape** p1;    // s1 and s2 are void*, cannot use "*s1" to get the content that s1 points to
    CShape** p2;
    p1 = (CShape**) s1; // s1 and s2 point to element of CShape* pShapes[]
    p2 = (CShape**) s2;
    a1 = (*p1)->Area();
    a2 = (*p2)->Area();
    if(a1 < a2){
        return -1;
    }
    else if(a2 < a1){
        return 1;
    }
    else{
        return 0;
    }
}