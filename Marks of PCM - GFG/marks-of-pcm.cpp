//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    struct Marks{
      int phy;
      int chem;
      int maths;
      Marks()
      {
          
      }
      Marks(int p, int c, int m)
      {
          phy = p;
          chem = c;
         maths = m;
      }
    };
    static bool mycomp(Marks m1, Marks m2)
    {
        // retrun true if they are place correctly
        // return false when they are placed incorrectly and the sorting will be donw
        if(m1.phy<m2.phy)
        {
            return true;
        }
        else if(m1.phy==m2.phy)
        {
            if(m1.chem<m2.chem)
            {
                return false;
            }
            else if(m1.chem==m2.chem)
            {
                if(m1.maths<m2.maths)
                {
                    return true;
                }
                return false;
                
            }
            return true;
        }
    
        return false;
    }
    
    void customSort (int phy[], int chem[], int math[], int N)
    {
        // vector<Marks>student(N);
        // for(int i = 0;i<N;i++)
        // {
        //     Marks s1(phy[i],chem[i],math[i]);
        //     student[i]=s1;
        // }
        vector<Marks>student(N);
        for(int i = 0;i<N;i++)
        {
            Marks m1 = Marks(phy[i],chem[i],math[i]);
           student[i]=m1;
        }
        sort(student.begin(), student.end(),mycomp);
        for(int i= 0;i<N;i++)
        {
            phy[i]=student[i].phy;
            chem[i]=student[i].chem;
            math[i]=student[i].maths;
        }
        
        
        
       
        
        
        
    
        
        
    } 
};

//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends