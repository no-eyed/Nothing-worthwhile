#include<iostream>

using namespace std;

static int colu,row1,all_sums=0;
static char all_path[50];
int h,v;

void right(int *arr,int sum,int h,int v,char path[]);
void down(int *arr,int sum,int h,int v,char path[]);
void max_gold(int * arr,int row,int col);

int main()
{
    cout<<"Input dimensions of 2d-array (M x N) : ";
    int row,col,i,j;
    cin>>row>>col;
    row1=row-1;
    colu=col-1;
    int arr[row][col];
    cout<<"Now, input array\n";
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    max_gold(&arr[0][0],row,col);
    return 0;
}

void max_gold(int * arr,int row,int col)
{
    //cout<<"No output except this";
    int sum=*arr,i;
    //cout<<"0 0 sum :"<<sum<<endl;
    h=0;
    v=0;
    char path[colu+row1];
    for(i=0;i<colu+row1;i++)
        path[i]='0';
    down(arr,sum,h,v,path);
    right(arr,sum,h,v,path);
    cout<<"Maximum gold coins = "<<all_sums<<endl;
    //path_p(path,);
    cout<<"Path = ";
    for(i=0;i<colu+row1;i++)
        cout<<all_path[i];
}

void right(int *arr,int sum,int h,int v,char path1[])
{
    int i; char path[colu+row1+1];
    for(i=0;i<colu+row1;i++)
        path[i]=path1[i];
    if(h<colu)
    {
        arr++;
        h++;
        sum=sum+*arr;
        i=0;
        while(path[i]!='0')
        {
            i++;
        }
        path[i]='h';
        //path=path_p(path,0);
        //cout<<v<<" "<<h;
        //cout<<" right sum is "<<sum<<" path "<<path<<endl;
    }
    if(h==colu && v<row1)
    {
        //cout<<"\nright to down\n";
        //arr=arr+colu+1;
        //v++;
        down(arr,sum,h,v,path);
    }
    if(v==row1 && h==colu)
    {
        //cout<<v<<" "<<h;
        //cout<<" right sum is "<<sum<<endl;
        if(all_sums<sum)
        {
            all_sums=sum;
            for(int i=0;i<colu+row1+1;i++)
            {
                all_path[i]=path[i];
            }
        }
        return;
    }
    if(h<colu && v<row1)
    {
        right(arr,sum,h,v,path);
        down(arr,sum,h,v,path);
    }

}

void down(int *arr,int sum,int h,int v,char path1[])
{
    int i; char path[colu+row1+1];
    for(i=0;i<colu+row1;i++)
        path[i]=path1[i];
    if(v<row1)
    {
        arr=arr+colu+1;
        v++;
        sum=sum+*arr;
        i=0;
        while(path[i]!='0')
        {
            i++;
        }
        path[i]='v';
        //path=path_p(path,0);
        //cout<<v<<" "<<h;
        //cout<<" down sum is "<<sum<<" path "<<path<<endl;
    }
    if(h<colu && v==row1)
    {
        //cout<<"\ndown to right\n";
        //arr++;
        //h++;
        right(arr,sum,h,v,path);
    }
    if(v==row1 && h==colu)
    {
        //cout<<v<<" "<<h;
        //cout<<" down sum is "<<sum<<endl;
        if(all_sums<sum)
        {
            all_sums=sum;
            for(int i=0;i<colu+row1+1;i++)
            {
                all_path[i]=path[i];
            }
        }
        return;
    }
    if(h<colu && v<row1)
    {
        down(arr,sum,h,v,path);
        right(arr,sum,h,v,path);
    }
}

/*char* path_p(char *path,int v_h)
{
    int i=0;
    if(v_h==0)
    {
        while(*path!='0')
        {
            path++;
        }
        ++path;
        *path='h';
    }
    else if(v_h==1)
    {
        while(*path!='0')
        {
            path;
        }
        path++;
        *path='v';
    }
    return path;
}*/

