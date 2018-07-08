#include<iostream>
using namespace std;
int a[9];
int tmp[9];
int main(){
    for(int i=0;i<9;i++) cin>>a[i];
    for(int i1=0;i1<4;i1++){
        for(int i2=0;i2<4;i2++){
            for(int i3=0;i3<4;i3++){
                for(int i4=0;i4<4;i4++){
                    for(int i5=0;i5<4;i5++){
                        for(int i6=0;i6<4;i6++){
                            for(int i7=0;i7<4;i7++){
                               for(int i8=0;i8<4;i8++){
                                   for(int i9=0;i9<4;i9++){
                                        tmp[0]=(a[0]+i1+i2+i4)%4; //A
                                        tmp[1]=(a[1]+i1+i2+i3+i5)%4; //B
                                        tmp[2]=(a[2]+i2+i3+i6)%4; //C
                                        tmp[3]=(a[3]+i1+i4+i5+i7)%4; //D
                                        tmp[4]=(a[4]+i1+i3+i5+i7+i9)%4; //E
                                        tmp[5]=(a[5]+i3+i5+i6+i9)%4; //F
                                        tmp[6]=(a[6]+i4+i7+i8)%4; //G
                                        tmp[7]=(a[7]+i5+i7+i8+i9)%4; //H
                                        tmp[8]=(a[8]+i6+i8+i9)%4; //I
                                        int i;
                                        for(i=0;i<9;i++){
                                            if(tmp[i]!=0) break;
                                        }
                                        if(i==9){
                                            for(int i=i1;i>0;i--) cout<<"1 ";
                                            for(int i=i2;i>0;i--) cout<<"2 ";
                                            for(int i=i3;i>0;i--) cout<<"3 ";
                                            for(int i=i4;i>0;i--) cout<<"4 ";
                                            for(int i=i5;i>0;i--) cout<<"5 ";
                                            for(int i=i6;i>0;i--) cout<<"6 ";
                                            for(int i=i7;i>0;i--) cout<<"7 ";
                                            for(int i=i8;i>0;i--) cout<<"8 ";
                                            for(int i=i9;i>0;i--) cout<<"9 ";
                                            cout<<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
