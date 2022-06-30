#include <iostream>
using namespace std;

typedef long long ll;
int n[400000000];//store to speed up
int main() 
{
    ll mans=1;
    ll ans=0;
    ll lowerrange=2;
    ll upperrange=4000000;
    cout<<"Lower range: ";
    cin>>lowerrange;
    cout<<"Upper range: ";
    cin>>upperrange;
    if(lowerrange<=1){
        cout<<"Invalid lower range, try again!"<<endl;
        return 0;
    }
    if(upperrange>4000000){
        cout<<"The upper range is too high, try again!"<<endl;
        return 0;
    }
    for(ll i=lowerrange;i<=upperrange;i++){
      ll mcur=1;
      ll cur=i;
      while(cur!=1){
        if(cur<400000000){
            if(n[cur]!=0){
                mcur+=n[cur];
                break;
            }
        }
        if(cur%2==0){
          cur/=2;
        }else{
          cur=3*cur+1;
        }
        mcur++;
      }
      n[i]=mcur;
      if(mcur>mans){
        mans=mcur;
        ans=i;
      }
    }
    cout<<"The number which has the longest Collatz Chain within this range is: "<<ans<<endl;
    cout<<"Its length is: "<<mans<<endl;
    cout<<"Would you like to get the full chain?(Y/N)";
    char c;
    cin>>c;
    while(c!='Y' and c!='N'){
        cout<<"Please input a valid character:";
        cin>>c;
    }
    ll cur;
    if(c=='Y'){
        cur=ans;
        while(cur!=1){
            cout<<cur<<endl;
            if(cur%2==0){
                cur/=2;
            }else{
                cur=3*cur+1;
            }
        }
        cout<<"1"<<endl;
        cout<<"Thanks! Bye for now~";
    }
    if(c=='N'){
        return 0;
    }
    return 0;
}
