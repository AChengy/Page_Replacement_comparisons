//
// Created by Alex on 12/6/2015.
//

#include "LRU.h"

#include<stdio.h>

int LRU(int nframes, int npages, int *pages)
{
    int fframe[10],used[10],index;
    int count,n1,k,nf,np=0,tmp,i;
    int flag=0,pf=0;


    nf = nframes;
    for(i=0;count<nf;count++)
        fframe[count]=-1;

//loop through the pages
    np = npages;
    for(count=0;count<np;count++)
    {
      //set the flag to 0 to start
        flag=0;
        //loop through the pages
        for(n1=0;n1<nf;n1++)
        {
          //if the page is in the frame then break and set the flag to 1
            if(fframe[n1]==pages[count])
            {
                flag=1;break;
            }
        }
/* program for lru page replacement algorithm in c */
//if the page wasn't in the frame array then it page faults
        if(flag==0)
        {
            for(n1=0;n1<nf;n1++) used[n1]=0; //set all used to 0 for the number of frames
            //have to adjust the page frame to keep track of the recently used
            for(n1=0,tmp=count-1;n1<nf-1;n1++,tmp--)
            {
                for(k=0;k<nf;k++)
                {
                    if(fframe[k]==pages[tmp])
                        used[k]=1;
                }
            }
            for(n1=0;n1<nf;n1++)
                if(used[n1]==0) //look for the page frame that was not used
                    index=n1;
            fframe[index]=pages[count]; //have the new page frame replace it
            pf++; //increase the page fault count
        }
    } // lru algorithm in c
    return pf;

}
