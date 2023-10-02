#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

bool big_cmp( char a, char b ){
  return a > b;
}

long long StringToLL( string s ){
  stringstream ss;
  long long num;
  ss << s;
  ss >> num;
  return num;
}

string LLToString( long long ll ){
  stringstream ss;
  string s;
  ss << ll;
  ss >> s;
  return s;
}

int main(){
  string s;
  long long a, b;
  set<long long> visited;
  while( getline( cin, s ) && s != "0" ){
    visited.clear();

    printf( "Original number was %s\n", s.c_str() );
    while(1){
      sort( s.begin(), s.end(), big_cmp );//greater<char>()
      a = StringToLL(s);
      sort( s.begin(), s.end() );
      b = StringToLL(s);
      printf( "%lld - %lld = %lld\n", a, b, a-b );
      if( visited.find(a-b) != visited.end() ) break;
      visited.insert(a-b);
      s = LLToString(a-b);
    }
    printf( "Chain length %d\n\n", visited.size()+1 );
  }
  return 0;
}
