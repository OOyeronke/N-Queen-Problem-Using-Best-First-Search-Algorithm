#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[])
{ 
    cout<<"Hopfield Artificial Neural Network (ANN)"<<endl<<endl;
   // srand(time(NULL));
              
    int a, x, y, z, add;
    
    cout << "Enter the number of input pattern" << endl;
	cin >> a;
	cout << endl;
    cout<<"Training patterns:"<<endl<<endl;
   
    int b = static_cast<int>(0.15f * a); // Converting float to int
    int* pattern = new int[b * a];
    
    for(y = 0; y < b; y++)     
    {
        for(x = 0; x < a; x++) 
        {
            pattern[y * a + x] = rand()%2;
            cout<<pattern[y * a + x];
        }
        cout<<endl;
    }
    cout<<endl;
    
  
    int* w = new int[a * a];
    for(y = 0; y < a; y++)
        for(x = y; x < a; x++)
            if(x == y)
                w[y * a + x]=0;
            else
            {
                add = 0;
                for(z = 0; z < b; z++)
                    add +=(pattern[z * a + x]*2-1)*(pattern[z * a + y]*2-1);
                w[y * a + x] = add;
                w[x * a + y] = add;
            }


    cout<<"The weight matrix:"<<endl<<endl;
    for(y = 0; y < a; y++)
    {
        for(x = 0; x < a; x++)
            printf("%2d ",w[y * a + x]); // %2d will fill the empty column on left with space 
        cout<<endl;
    }
    cout<<endl;

    cout<<"Pattern-recognition Test:"<<endl<<endl;
        int selectedPattern = rand()%b;
    cout<<"Test pattern selected:"<<endl;
    for( x = 0; x < a; x++)
    {
        cout<<pattern[selectedPattern * a + x];
    }
    cout<<endl<<endl;
    
    int errorPercentage = 10;
    cout<<"Initial network state:"<<endl;
    cout<<"The test pattern w/ "<<errorPercentage<<"% error added:"<<endl;
    int* neuron = new int[a];     
    int* neuron_prev = new int[a];
    for(x = 0; x < a; x++)
    {
        neuron[x] = pattern[selectedPattern * a + x];
        if(rand()%100 < errorPercentage) neuron[x] = 1-neuron[x];
        cout<<neuron[x];
        neuron_prev[x] = neuron[x]; 
    }
    cout<<endl<<endl;

   
    int ctr_unchg = 0;

   
    int ctr = 0;
    
    while(ctr_unchg < 100 && ctr < 1000) 
    {

        
        for(z = 0; z < a; z++) 
        {
            y = rand() %a;
            add = 0;
            for(x = 0; x < a; x++)
                if(x!=y)
                    add += neuron[x] * w [y * a + x];
            if(add >= 0)
                neuron[y] = 1;
            else
                neuron[y] = 0;
        }

       
        bool changed=false;
        for(z = 0; z < a; z++)
            if(neuron[z] !=neuron_prev[z])
            {
                changed=true;
                break;
            }
        if(changed == false)
            ctr_unchg++;
        else 
            ctr_unchg=0;

        
        for(z = 0; z < a; z++)
            neuron_prev[z] = neuron[z];

        ctr++;              
    }

       if(ctr_unchg>=100)
    {
        cout<<"Converged network state:"<<endl<<endl;
        for(x = 0; x < a; x++)
            cout<<neuron[x];
        cout<<endl<<endl;

       
       int addDif = 0; 
        for(x = 0; x < a; x++)
            if(neuron[x]!=pattern[selectedPattern * a + x])
                addDif++;
        cout<<"Convergence error percentage:"<<100*addDif / a<<endl;
    }
    else
        cout<<"The network did not reach the convergence limit set!"<<endl;
    
    
    delete []pattern;
    delete []w;
    delete []neuron;
    delete []neuron_prev;

        return 0;
}
