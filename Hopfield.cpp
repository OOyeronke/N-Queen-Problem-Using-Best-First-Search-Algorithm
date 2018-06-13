//#include <iostream>
//#include <conio.h> 
#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[])
{ 
    cout<<"Hopfield Artificial Neural Network (ANN):"<<endl<<endl;
    srand(time(NULL));
    int n=8;          
    int i,j,k,add;
    
   
    cout<<"Training patterns:"<<endl<<endl;
   
    int m=static_cast<int>(0.15f*n);
    int* pattern=new int[m*n];
    for(j=0;j<m;j++)     
    {
        for(i=0;i<n;i++) 
        {
            pattern[j*n+i]=rand()%2;
            cout<<pattern[j*n+i];
        }
        cout<<endl;
    }
    cout<<endl;
    
  
    int* w=new int[n*n];
    for(j=0;j<n;j++)
        for(i=j;i<n;i++)
            if(i==j)
                w[j*n+i]=0;
            else
            {
                add=0;
                for(k=0;k<m;k++)
                    add+=(pattern[k*n+i]*2-1)*(pattern[k*n+j]*2-1);
                w[j*n+i]=add;
                w[i*n+j]=add;
            }


    cout<<"The weight matrix:"<<endl<<endl;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
            printf("%2d ",w[j*n+i]);
        cout<<endl;
    }
    cout<<endl;

    cout<<"Pattern-recognition Test:"<<endl<<endl;
        int selectedPattern=rand()%m;
    cout<<"Test pattern selected:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<pattern[selectedPattern*n+i];
    }
    cout<<endl<<endl;
    
    int errorPercentage=10;
    cout<<"Initial network state:"<<endl;
    cout<<"The test pattern w/ "<<errorPercentage<<"% error added:"<<endl;
    int* neuron=new int[n];     
    int* neuron_prev=new int[n];
    for(i=0;i<n;i++)
    {
        neuron[i]=pattern[selectedPattern*n+i];
        if(rand()%100<errorPercentage) neuron[i]=1-neuron[i];
        cout<<neuron[i];
        neuron_prev[i]=neuron[i]; 
    }
    cout<<endl<<endl;

   
    int ctr_unchg=0;

   
    int ctr=0;
    
    while(ctr_unchg<100 && ctr<1000) 
    {

        
        for(k=0;k<n;k++) 
        {
            j=rand()%n;
            add=0;
            for(i=0;i<n;i++)
                if(i!=j)
                    add+=neuron[i]*w[j*n+i];
            if(add>=0)
                neuron[j]=1;
            else
                neuron[j]=0;
        }

       
        bool changed=false;
        for(k=0;k<n;k++)
            if(neuron[k]!=neuron_prev[k])
            {
                changed=true;
                break;
            }
        if(changed==false)
            ctr_unchg++;
        else
            ctr_unchg=0;

        
        for(k=0;k<n;k++)
            neuron_prev[k]=neuron[k];

        ctr++;              
    }

       if(ctr_unchg>=100)
    {
        cout<<"Converged network state:"<<endl<<endl;
        for(i=0;i<n;i++)
            cout<<neuron[i];
        cout<<endl<<endl;

       
       int addDif=0; 
        for(i=0;i<n;i++)
            if(neuron[i]!=pattern[selectedPattern*n+i])
                addDif++;
        cout<<"Convergence error percentage:"<<100*addDif/n<<endl;
    }
    else
        cout<<"The network did not reach the convergence limit set!"<<endl;
    
    // garbage collection
    delete []pattern;
    delete []w;
    delete []neuron;
    delete []neuron_prev;

        return 0;
}
