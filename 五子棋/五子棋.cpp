#include<bits/stdc++.h>
using namespace std;
const int MAX=15; 
class Modchage{
    public:
    void pshow()
    {
    	cout<<"                     "<<endl;
    	cout<<"                     "<<endl;
    	cout<<"             ˫����Ϸ��������Ϸ     "<<endl;
    	cout<<"                1.��ʼ����Ϸ"<<endl;
    	cout<<"                2.��ȡ����"<<endl; 
    	cout<<"                3.�뿪��Ϸ"<<endl;
	}
	void selectshow()
	{
		cout<<"                         "<<endl; 
		cout<<"�������Ӧ��ģʽ(1/2/3) :";
	}
}test; 
class Player{
	
	public: 
		int x,y,red,winround;//���һ��������Ϣ 
		char name[15];
	Player()
	{
		winround=0;
	}
	void win()
	{
		winround++;
	 } 
	void set(int xx,int yy)
	{
		x=xx,y=yy;
	}
	string red1()
	{
		if(red==0)
		{
			return  "��";
		}
		else return "��"; 
	}
}; 
class peceinformaion{
	public:
	pieceinformaion(){
			memset(data,0,sizeof(data));
			nowturn = 0;
		}
		int data[MAX][MAX];
	    int nowx,nowy;
	    int nowturn;
	    Player nowplys[2];
	void set1(int x,int y)
	{
		nowx=x,nowy=y;
	}
	void getinfpiece(int g)
	{
		if(g==1)
		cout<<"��";
		else 
		cout<<"��";
	}
		void getinfpiece1(int g)
	{
		if(g==1)
		cout<<"�� ";
		else 
		cout<<"�� ";
	}
	void proshow(){
			system("cls");
			cout<<"             ˫����Ϸ��������Ϸ     "<<endl;
			cout<<"               ��ǰ��ң�"<<nowplys[nowturn].name<<endl;
			cout<<"               ��ǰ��ɫ��"<<nowplys[nowturn].red1()<<endl;
			cout<<"            "<<endl;
			
	} 
	void show(){
			proshow();
			cout<<"     ";
			for(int i=0;i<MAX;i++)
			{cout<<i+1<<" ";
			 if(i<8)
			 cout<<" ";} 
			cout<<endl;
		for(int i=0;i<MAX;i++){
			if(i+1<10)
			cout<<i+1<<"   ";
		      else
		      cout<<i+1<<"  ";
			for(int j=0;j<MAX;j++){

				if(i==0&&j==0){
				if(!data[i][j])
				cout<<"����";
				else
				getinfpiece1(data[i][j]);
				}
			
				else if(j==0&&i==MAX-1){
				if(!data[i][j])
				cout<<"����";
				else
				getinfpiece1(data[i][j]);
				}
				
				else if(i==0&&j==MAX-1){
					if(!data[i][j])
						cout<<"�� ";
				else
				getinfpiece(data[i][j]);
				}
				
				else if(i==MAX-1&&j==MAX-1){
				if(!data[i][j])
						cout<<"�� ";
				else
				getinfpiece(data[i][j]);
				}
				
				else if(i==0){
				if(!data[i][j])
					 cout<<"�ӡ�";
				else
				getinfpiece1(data[i][j]);
				}

				else if(j==0){
					if(!data[i][j])
						cout<<"�ġ�";
				else
				getinfpiece1(data[i][j]);
				} 
			
			
				else if(j==MAX-1){
					if(!data[i][j])
					    cout<<"�� ";
				else
				getinfpiece(data[i][j]);
						if(i==4)
						{
							cout<<"               	Remark: ����R��������";
						}
						if(i==5)
						{
							cout<<"               	        ����S��������";
						}
						if(i==6)
						{
							cout<<"               	        ����Q�����˳���Ϸ";
						}
						if(i==7){
							cout<<"                        ����VS����:"<<nowplys[0].winround<<":"<<nowplys[1].winround; 
						} 
				} 
			
				else if(i==MAX-1){
				if(!data[i][j])
			         cout<<"�ۡ�";
				else
				getinfpiece1(data[i][j]);
				}
				
				else{
				if(!data[i][j])
					 cout<<"�ࡪ";
				else
				getinfpiece1(data[i][j]);
				}
				
			}	
			cout<<endl;
		}
		cout<<"        "<<endl;
    	cout<<"��������Ҫ�µ���������:"<<endl; 
	}

};
class Op:public peceinformaion{ //�̳���Ϣ�� 
	public:
		Op(const Op &a):peceinformaion(a){} 
		Op(){} 
		bool check() //�ж��Ƿ����  4������ 
		{
			int flag=0;    //�Ƿ�ɹ� 
			int tx=nowx;
			int ty=nowy;   //��ǰ���� 
			int flag1=nowturn+1; //��ǰ��ɫ��
			int p=0; 
		while(data[tx][ty]==flag1) // | 
			{
			        p++;
						if(p==5)
					{
						flag=1;
					}
					if(tx>0)
					{
						tx--;
						continue;
					}
					else
						break;
				
		    }
		    p--;
		    tx=nowx;
		 while(data[tx][ty]==flag1) 
			{
				
			        p++;	
					if(p==5)
					{
						flag=1;
			
					}
					if(tx<14)
					{
						tx++;
						continue;
					}
					else
						break;
			
		    }		                     
			tx=nowx;
			ty=nowy;
			p=0;						 
				while(data[tx][ty]==flag1) // --
			{
			        p++;
						if(p==5)
					{
						flag=1;
						break;
					}
					if(ty>0)
					{
						ty--;
						continue;
					}
					else
						break;
				
		    }
		    p--;	
			ty=nowy;
				 while(data[tx][ty]==flag1) 
			{
				
			        p++;	
					if(p==5)
					{
						flag=1;
			
					}
					if(ty<14)
					{
						ty++;
						continue;
					}
					else
						break;
			
		    }					       
		    tx=nowx;
			ty=nowy;
			p=0;						 
				while(data[tx][ty]==flag1) // ����б�� 
			{
			        p++;
						if(p==5)
					{
						flag=1;
						break;
					}
					if(ty>0&&tx>0)
					{
						ty--;
						tx--;
						continue;
					}
					else
						break;
				
		    }
		    p--;	
			ty=nowy;
			tx=nowx;
				 while(data[tx][ty]==flag1) 
			{
				
			        p++;	
					if(p==5)
					{
						flag=1;
			
					}
					if(ty<14&&tx<14)
					{
						ty++;
						tx++;
						continue;
					}
					else
						break;
			
		    }		    
		    tx=nowx;
			ty=nowy;
			p=0;						 
				while(data[tx][ty]==flag1) // ����б�� 
			{
			        p++;
						if(p==5)
					{
						flag=1;
						break;
					}
					if(ty<14&&tx>0)
					{
						ty++;
						tx--;
						continue;
					}
					else
						break;		
		    }
		    p--;	
			ty=nowy;
			tx=nowx;
				 while(data[tx][ty]==flag1) 
			{
				
			        p++;	
					if(p==5)
					{
						flag=1;
			
					}
					if(ty>0&&tx<14)
					{
						ty--;
						tx++;
						continue;
					}
					else
						break;
			
		    }	
		    if(flag)
		        return true; 
		        else
		        return false;
		}
		void retunpi() //���� 
		{	
		    nowturn^=1;
			data[nowplys[nowturn].x][nowplys[nowturn].y]=0;
			show();
		}
		void putpi(int x,int y)//����  1�� 2�� 
		{
			data[x-1][y-1]=nowturn+1;
		    nowplys[nowturn].set(x-1,y-1);
		    set1(x-1,y-1); 
			show();	
		  if(check())
		{
		
		    nowplys[nowturn].win(); 	
			show();
			cout<<endl;
			cout<<nowplys[nowturn].name<<":�����Ϸʤ��"<<endl;
			cout<<"�����������ʼ����Ϸ"<<endl;
			int t=getchar();
			t=getchar();
		    memset(data,0,sizeof(data)); 
		    nowturn=0;
		    show();
		 }	
		else{
			 nowturn^=1; //�л� 0�������1 1�������2 
			 show();
			}
		} 
}newstart,restart;
int main()

{	

  test.pshow(); 
  test.selectshow();
  int time;
  cin>>time;
  if(time==1){
  	system("cls");
  	newstart.nowturn=0;
  	cout<<"���������1(Ĭ������)������:";
  	cin>>newstart.nowplys[0].name;
  	newstart.nowplys[0].red=0;
  	cout<<endl;
  	cout<<"���������2(Ĭ�Ϻ���)������:";
  	cin>>newstart.nowplys[1].name;
  	getchar();
  	newstart.nowplys[1].red=1;
  	cout<<"    "; 
  	newstart.show();
  }
  else if(time==2)
  {
        std::ifstream fin("Savepiece", std::ios_base::in | std::ios_base::app | std::ios_base::binary); 
        fin.read((char*)&newstart, sizeof(Op));
        newstart.show();	
 
  }
  else
     return 0;
  	while(1)   //��ʼ���� 
  	{
  		string ch;
  		int x=0,y=0;
  		cin>>ch;
  		if(ch=="R")
  		{   
  		    newstart.retunpi();
  			continue;
		  }
		  else if(ch=="Q")
		  {
		  	return 0;
		  }
		  else if(ch=="S")
		  {
		    std::ofstream fout("Savepiece", std::ios_base::out | std::ios_base::binary);
		    fout.write((char*)&newstart, sizeof(Op));
			int ppp=getchar();
			cout<<"������ϣ������������"<<endl; 
			ppp=getchar();
			fout.close();
			restart=newstart;
			restart.show(); 
			continue;
	      }
		  else
		  {
		  	
		  	if(ch.length()==2)
		  	{
		  		x=ch[1]-'0'+(ch[0]-'0')*10;
			  }
			  else
			     x=ch[0]-'0';
		  	  cin>>y;
		if(0<x&&x<=15&&y>0&&y<=15&&newstart.data[x-1][y-1]==0){
			   newstart.putpi(x,y);
		  }
		  else{
		  	cout<<"����������"<<endl;
		  	int ppp=getchar();
			continue; 
		  }
  	
	  }
}
	return 0;
}
