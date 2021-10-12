#include<bits/stdc++.h>
using namespace std ;

typedef pair< int , pair<int, int> > P  ;
vector<pair<int,int>>ans ;
vector<pair<int,int>>parent ;
int row[4]={1,-1,0,0} ;
int col[4]={0,0,1,-1} ;

int RR , CC ;
int flag = 0 ;

void ShowMap( vector<vector<int>>mp )
{
	int row = mp.size() ;
	int col = mp[0].size() ;

	std::cout<<"\n\n-----------------------------------------------------------------------------"<<endl<<endl ;
	for( int i = 0 ; i < row ; i++ )
	{
		for( int j = 0 ; j < col ; j++ )
		{
			std::cout<<" | "<<mp[i][j]<<"\t" ;
		}

		std::cout<<" | "<<endl ;
	}
	
	std::cout<<endl ;	
	std::cout<<"-----------------------------------------------------------------------------"<<endl<<endl ;

}


void BestFirstSearch( vector<vector<int>>board , vector<vector<int>>mp , pair<int,int>start,pair<int,int>end ,int parentX[100][100] , int parentY[100][100])
{
	// 1 -> obstacle
	// 0 -> path 
	vector<vector<bool>> visited(RR, vector<bool>(CC,false)) ;
    priority_queue< P > pq ;
    pq.push({ -mp[start.first][start.second] , start } ) ;
	P tmp ;

    while ( !pq.empty() ) 
	{

        int x = pq.top().second.first ;
		int y = pq.top().second.second ;
		P tmp ;
		visited[x][y] = true ;
        pq.pop() ;

			if ( mp[x][y] == 0 )		
			{
                flag = 1 ;
                break ;
            }
			
            for(int i=0;i<4;i++)
            {
                int xt = x+row[i] ;
                int yt = y+col[i] ;

                if( ( xt >=0 && xt < RR ) && ( yt >= 0 && yt < CC ) && !visited[xt][yt] && board[xt][yt] != 1 )
                {
                    //cout<<xt<<" "<<yt<<" ---> " ;
                    tmp.first = -mp[xt][yt] ;
				    tmp.second = {xt,yt} ;
                    pq.push( tmp ) ;
                    parentX[xt][yt] = x ;
				    parentY[xt][yt] = y ;
                }

            }
            

    }
	cout<<endl;

}


void Manhattan_Distance( pair<int,int> x , pair<int,int> y , vector<vector<int> >& p )
{
 

    for (int i = 0; i < p.size(); i++) 
		for(int j = 0 ; j < p[0].size() ; j++ )
		{
			p[i][j] = abs(i-y.first)+abs(j-y.second ) ;

		}	

	return ;
}
void PrintPath( pair<int,int>start,pair<int,int>end,int parentX[100][100] ,int parentY[100][100] )
{

std::cout<<"-----------------------------------------------------------------------------"<<endl<<endl ;

	std::cout<<"Best First Searched Path is :: --->>> \n "<<endl<<" Ends here "<<endl  ;
	int i = end.first , j = end.second ;

	if(  flag )
	{
		while( 1 )
		{
			std::cout<<" ( "<<i<<" , "<<j<<" )  <--  "<<endl ;
			//i = parent[i][j].first ;
			//j = parent[i][j].second ;
			if( i == start.first && j == start.second )
				break ;

			i = parentX[i][j] ;
			j = parentY[i][j] ;
		}
		std::cout<<"<------- Starts here "<<endl ;
		

	}
	else
		std::cout<<"No Path exists\n"<<endl ;
        
	std::cout<<endl ;



}
void printXYtrip(int parentX[100][100],int parentY[][100],int r ,int c,pair<int,int>start)
{
    std::cout<<"\n\nThe backTracking Matrix : "<<endl ;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			std::cout<<" ( "<<parentX[i][j]<<" , "<<parentY[i][j]<<" ) "<<"\t" ;
		std::cout<<endl ;
	}
	std::cout<<endl<<endl<<endl ;

}
int main()
{
	int row,col,R,C ;
	std::cout<<"Enter your map rows and columns"<<endl ;
	cin>>R ;
	cin>>C ;
	RR = R ;
	CC = C ;

	vector<vector<int>>board ;
	vector<vector<int>>ManHattanBoard(R,vector<int>(C,0)) ;
	
	vector<int>res ;
	pair<int,int>start ;
	pair<int,int>end ;
	int parentX[100][100] ;
	int parentY[100][100] ;
	
	memset(parentX,0,sizeof(parentX)) ;
	memset(parentY,0,sizeof(parentY)) ;

	int tmp = 0 ;

std::cout<<"-----------------------------------------------------------------------------"<<endl ;

	std::cout<<"Enter the starting co-ordinates"<<endl ;
	cin>>row ;
	cin>>col ;
	start.first = row ;
	start.second = col ;

//----------------------------------------

//-----------------------------------------

std::cout<<"-----------------------------------------------------------------------------"<<endl ;

	std::cout<<"Enter the target co-ordinates"<<endl ;
	cin>>row ;
	cin>>col ;
	end.first = row ;
	end.second = col ;

std::cout<<"-----------------------------------------------------------------------------"<<endl ;

	std::cout<<"Enter the map\n"<<endl ;

	for( int i = 0 ; i < R ; i++ )
	{
		for( int j = 0 ; j < C ; j++ )
		{
			cin>>tmp ;
			res.push_back(tmp) ;

		}
		board.push_back(res) ;
		res.clear() ;
	}
	vector<vector<bool>> visited(RR, vector<bool>(CC,false)) ;

	std::cout<<"\n\n---------------------------------- The Given Map -------------------------------------------"<<endl<<endl ;
	ShowMap(board) ;
	Manhattan_Distance(start,end,ManHattanBoard) ;
	std::cout<<"\n\n---------------------------- The Manhattan Distance Map ------------------------------------"<<endl<<endl ;
	ShowMap(ManHattanBoard) ;

	BestFirstSearch(board,ManHattanBoard,start,end,parentX,parentY) ;
	PrintPath(start,end,parentX,parentY) ;
	printXYtrip(parentX,parentY,R,C,start) ;



	return 0 ;
}












