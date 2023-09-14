#include<stdio.h>
#include"sharedfile.h"
#include<stdbool.h>



bool CheckPerfect(int iNo)
{
      int iCnt=0;
      int iSum=0;
      
          if(iNo<0)
          {
            iNo=-iNo;
          }

        for(iCnt=iNo/2;((iCnt>=1) && (iSum<=iNo));iCnt--)
          {
            if((iNo%iCnt)==0)
              {
              iSum=iSum+iCnt;
            }
          
          }

          if(iSum==iNo)
          {
            return true;
          }

        else
          {
            return false;
          }
            
      }

bool CheckPrime(int iNo)
{
  int iCnt=0;
    
  for(iCnt=2;iCnt<=iNo/2;iCnt++)
  {
    if(iNo%iCnt==0)
    {
       break;
     }
  }
    
  if(iCnt>iNo/2)   //if(icnt==(ino/2)+1)
  {
    return true;
  }
  else
  {
    return false;
  }

}

bool Chkeven(int iNo)
{
  bool bflag=false;
  if(iNo%2==0)
  {
    bflag=true;
               
  }
    return bflag;
}

bool Chkodd(int iNo)
{
  bool bflag=false;
  if(iNo%2!=0)
  {
    bflag=true;
               
  }
    return bflag;
}


int CountFact(int iNo)
{
  int iCnt=0;
  int iCount=0;
  int iSum=0;
  for(iCnt=1;iCnt<=iNo/2;iCnt++)
  {
    if(iNo%iCnt==0)
    {
      iCount++;
    }
   }
    return iCount;
}

void DisplayFact(int iNo)
{
  int iCnt=0;
  for(iCnt=1;iCnt<=iNo/2;iCnt++)
  {
    if(iNo%iCnt==0)
    {
      printf("factor are:%d\n",iCnt);
    }
  }
}


void DisplayNonFact(int iNo)
{
  int iCnt=0;
  for(iCnt=1;iCnt<=iNo/2;iCnt++)
  {
    if(iNo%iCnt!=0)
    {
      printf("%d\n",iCnt);
    }
  }
}

 int Power(int iNo,int iPower)
{
  int iCnt=0;
  int iMult=1;
  for(iCnt=1;iCnt<=iPower;iCnt++)
  {
              
    iMult=iMult*iNo;
  }
  return iMult;
}

int SumFact(int iNo)
{
    int iCnt=0;
    int iSum=0;
    for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
      if(iNo%iCnt==0)
      {
        iSum=iSum+iCnt;
      }
    }
    return iSum;
}
