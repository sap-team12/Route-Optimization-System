#include<bits/stdc++.h>
using namespace std;

//struture for each node
struct node
{
//every node will contain x and y coordinates and number of rovers present at that node
    int x,y,number_of_rover;
};

//structure for each blocks denoted by house
struct house
{
//every house will contain 4 coordinates i.e.(x1,y1)(x2,y2)(x3,y3)(x4,y4)
    int x1,x2,x3,x4;
    int y1,y2,y3,y4;
};

//structure for each rover
struct rover
{
//every rover will contain current distance,total distance,present coordinates,type of bussiness it delivers
    int total_dis;
    int current_dis;
    int x;
    int y;
    float total_pay;
    string type;
};


//generate shortest path form source to destination
string generate_path(int src1, int src2, int dest1, int dest2)
{
    int horizontal=dest1-src1;
    int vertical=dest2-src2;
    char c; string ans="";
    if(horizontal>0)
    {
        c='R';
    }
    else
    {
        c='L';
    }
    horizontal=abs(horizontal)/10;
    while(horizontal--)
          ans+=c;
    if(vertical>0)
    {
        c='D';
    }
    else
    {
        c='U';
    }
    vertical=abs(vertical)/10;
    while(vertical--)
          ans+=c;

    return ans;
}

//it generates overall revenue form rovers
float generate_rev(unordered_map<int,rover> &mp)
{
    float bill=0;
    for(auto a: mp)
    {
    rover object = a.second;
        bill+=object.total_pay;
    }
    return bill;
}

//date time
string time_cal()
{
// Declaring argument for time()
time_t tt;

// Declaring variable to store return value of
// localtime()
struct tm * ti;

// Applying time()
time (&tt);

// Using localtime()
ti = localtime(&tt);
return asctime(ti);
}

//current amount for each  distance of rover
float now_amount(int dist)
{
    float tot_bill;
    if(dist>10000)
    {
    return -1;
    }
    else if(dist>=0 && dist <=1000)
    {
        tot_bill=dist*(0.50/100);
    }
    else if(dist>1000 && dist<=2000)
    {


        tot_bill=dist*(0.75/100);
    }
    else
    {

        tot_bill=dist*(0.85/100);
    }
    return tot_bill;
}

int main()
{
//file handling
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string prev_time = time_cal().substr(0,3);

    int i,j,c=1;
    int xx1,xx2,xx3,xx4;
    int yy1,yy2,yy3,yy4;

    // unordered_mp conatins house id and coordintes
    unordered_map<int,house> ump;

    yy1=0;yy2=0;yy3=10;yy4=10;

    for(i=0;i<100;i++)
    {
        xx1=0;xx2=10;xx3=0;xx4=10;

        for(j=0;j<100;j++)
        {
            house house_code;
            house_code.x1=xx1;
            house_code.y1=yy1;
            house_code.x2=xx2;
            house_code.y2=yy2;
            house_code.x3=xx3;
            house_code.y3=yy3;
            house_code.x4=xx4;
            house_code.y4=yy4;
            ump[c]=house_code;
            c++;
            xx1=xx1+10;
            xx2=xx2+10;
            xx3=xx3+10;
            xx4=xx4+10;
        }
        yy1=yy1+10;
        yy2=yy2+10;
        yy3=yy3+10;
        yy4=yy4+10;
    }
    /*
    for(i=101;i<105;i++)
    {
        house house_code = ump[i];
    cout<<house_code.x1<<" "<<house_code.y1<<endl;
    }*/
    /*
    node odessa[101][101];
    for(i=0;i<101;i++)
    {
        for(j=0;j<101;i++)
        {
            odessa[i][j].x=i;
            odessa[i][j].y=j;
            odessa[i][j].number_of_rover=0;
        }
    }*/

    //unordered_map for rover conatins id and present cordinates
    unordered_map<int,rover> rover_mp;
    for(i=0;i<10;i++)
    {
        rover rover_ob;
        rover_ob.total_dis=0;
        rover_ob.current_dis=0;
        rover_ob.total_pay=0;
        rover_ob.x=0;
        rover_ob.y=0;
        rover_ob.type="null";
        rover_mp[i]=rover_ob;
    }

    char ch;
    cin>>ch;

    while(ch=='y')
{
   int h_id;
   cout<<"Enter house id ";
   cin>>h_id;
   cout<<h_id<<endl;
   cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

   house house_code = ump[h_id];
   int src_x=0,src_y=0,des_x=INT_MAX,des_y=INT_MAX,min_dis_house=INT_MAX,rover_ind=0;
   for(i=0;i<10;i++)
   {
       rover object = rover_mp[i];
       int distance = abs(object.x-house_code.x1)+abs(object.y-house_code.y1);
       if(distance<min_dis_house)
       {
           min_dis_house=distance;
           des_x=house_code.x1;
           des_y=house_code.y1;
           src_x=object.x;
           src_y=object.y;
           rover_ind=i;
       }
       distance = abs(object.x-house_code.x2)+abs(object.y-house_code.y2);
       if(distance<min_dis_house)
       {
           min_dis_house=distance;
           des_x=house_code.x2;
           des_y=house_code.y2;
           src_x=object.x;
           src_y=object.y;
           rover_ind=i;
       }
       distance = abs(object.x-house_code.x3)+abs(object.y-house_code.y3);
       if(distance<min_dis_house)
       {
           min_dis_house=distance;
           des_x=house_code.x3;
           des_y=house_code.y3;
           src_x=object.x;
           src_y=object.y;
           rover_ind=i;
       }
       distance = abs(object.x-house_code.x4)+abs(object.y-house_code.y4);
       if(distance<min_dis_house)
       {
           min_dis_house=distance;
           des_x=house_code.x4;
           des_y=house_code.y4;
           src_x=object.x;
           src_y=object.y;
           rover_ind=i;
       }
   }

   rover object1 = rover_mp[rover_ind];
   int max_dis = object1.total_dis+min_dis_house;

   if(max_dis<10000)
   {
   rover object = rover_mp[rover_ind];
   object.x=des_x;
   object.y=des_y;
   object.total_dis = max_dis;
   object.total_pay += now_amount(min_dis_house);
   rover_mp[rover_ind]=object;

   cout<<"Path to be followed by the rover : "<<generate_path(src_x,src_y,des_x,des_y)<<" with distance travelled : "<<min_dis_house<<" with cost : Rs."<<now_amount(min_dis_house)<<endl;
   rover object1 = rover_mp[rover_ind];
   cout<<" x "<<object1.x<<" "<<" y "<<object1.y<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   cin>>ch;
}
else
{
cout<<"Sorry, we cannot deliver your product "<<endl;
}

cout<<"Total Revenue after every delivery : Rs."<<generate_rev(rover_mp)<<endl;
cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;



//counter for counting days and monthly income for governor
int counter=0,monthly_income=0;
if(time_cal().substr(0,3)!=prev_time)
{
counter++;
cout<<" New Day";
cout<<"THe revenue for previous day is \n";
cout<<generate_rev(rover_mp)<<endl;

monthly_income += generate_rev(rover_mp);
prev_time=time_cal().substr(0,3);

   yy1=0;yy2=0;yy3=10;yy4=10;
   for(i=0;i<100;i++)
   {
       xx1=0;xx2=10;xx3=0;xx4=10;

       for(j=0;j<100;j++)
       {
           house house_code;
           house_code.x1=xx1;
           house_code.y1=yy1;
           house_code.x2=xx2;
           house_code.y2=yy2;
           house_code.x3=xx3;
           house_code.y3=yy3;
           house_code.x4=xx4;
           house_code.y4=yy4;
           ump[c]=house_code;
           c++;
           xx1=xx1+10;
           xx2=xx2+10;
           xx3=xx3+10;
           xx4=xx4+10;
       }
       yy1=yy1+10;
       yy2=yy2+10;
       yy3=yy3+10;
       yy4=yy4+10;
   }
       for(i=0;i<10;i++)
   {
       rover rover_ob;
       rover_ob.total_dis=0;
   rover_ob.current_dis=0;
       rover_ob.total_pay=0;
       rover_ob.x=0;
       rover_ob.y=0;
   rover_ob.type="null";
   rover_mp[i]=rover_ob;
}
}
if(counter==30)
{
cout<<"monthly_income of governer :Rs. "<<monthly_income<<endl;
counter=0;
monthly_income=0;
}
}
}
