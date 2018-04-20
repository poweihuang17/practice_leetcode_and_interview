class Solution {
public:
    string similarRGB(string color) {

        vector<int> origin;
        for(int i=1;i<6;i+=2)
        {
            int number=0;
            stringstream ss;
            ss<<std::hex<<color.substr(i,2);
            ss>>number;
            origin.push_back(number);
            //cout<<number<<endl;
        }
        
        int u=INT_MIN;
        string r;
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
            {
                for(int k=0;k<16;k++)
                {
                    int x=(i*17-origin[0]);
                    int y=(j*17-origin[1]);
                    int z=(k*17-origin[2]);
                    int number2=-(x*x+y*y+z*z);            
                    if(number2>u)
                    {
                        u=number2;
                        std::stringstream stream;
                        stream << std::hex << i<<i<<j<<j<<k<<k;
                        std::string result1( stream.str() );
                        
                        r="#"+result1;
                    }

                }
            }
        }
    return r;

    }
};