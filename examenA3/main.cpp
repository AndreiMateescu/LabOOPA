#include <iostream>

using namespace std;

class OneDimensionArray{
    protected:
        double* a;
        int n;
    public:
        OneDimensionArray(int dim=10){
            n = dim;
            a = new double[n];
        }
        ~OneDimensionArray(){ delete [] a; }
        OneDimensionArray& operator=(OneDimensionArray& p){
            if(&p == this)
                return *this;
            delete [] a;
            a = new double[n=p.n];
            for(int i=0;i<p.n;i++)
                a[i] = p.a[i];
            return *this;
        }
        double& operator[](int i){
            return a[i];
        }
        inline int getN(){return n;}

        inline double* getVect(){return a;}

        void afisare(){
            for(int i=0;i<n;i++)
                cout<<a[i]<<endl;
        }
        double f(int i,OneDimensionArray& p){
            return p[i];
        }

};

class StackInh : private OneDimensionArray{
private:
    double *stackk;
    int dimension;
public:
    StackInh(int dim=0){
        dimension = dim;
        stackk = new double[dim];
    }
    ~StackInh() {delete [] stackk;}

    void Copy(OneDimensionArray& p){
        dimension = p.getN();
        for(int i=0;i<dimension;i++)
            stackk[i] = f(i,p);
    }

    void afisareStack(){
        for(int i=0;i<dimension;i++)
            cout<<stackk[i]<<endl;
    }

    void push(int val){
        dimension++;
        for(int i=dimension-2;i>=0;i--)
            stackk[i+1] = stackk[i];
        stackk[0] = val;
    }

    bool IsEmpty(){
        if(dimension == 0)
            return true;
        else
            return false;
    }

    double pop(){
        if(IsEmpty()==false){
            double p = stackk[0];
            dimension--;
            for(int i=1;i<dimension;i++)
                stackk[i-1] = stackk[i];
            return p;
        }
    }
};

int main()
{
    OneDimensionArray a1(20);
    OneDimensionArray a2;

    for(int i=0;i<a1.getN();i++)
        a1[i] = 7.5;
    a2 = a1;

    StackInh stiva;
    stiva.Copy(a2);

    stiva.push(5);
    stiva.push(17);
    stiva.afisareStack();

    double x = stiva.pop();
    stiva.afisareStack();
    cout<<"X = "<<x;
    return 0;
}
