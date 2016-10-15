// Boggle.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

struct node{
  bool is_end;
  int prefix_count;
  struct node* child[26];
}*head;

void insert(string word){
  node* current = head;
  current->prefix_count++;
  for(unsigned int i=0; i<word.length()-1;++i){
    int letter = (int)word[i] - (int)'a';
    if(current->child[letter] == NULL){
      current->child[letter] = new node();
    }
    current->child[letter]->prefix_count++;
    current = current->child[letter];
  }
  current->is_end = true;
}

bool search(string word){
  node* current = head;
  for(unsigned int i=0;i<word.length();++i){
    if(current->child[((int)word[i] - (int)'a')] == NULL){
      return false;
    }
    current = current->child[((int)word[i] - (int)'a')];
  }
  return current->is_end;
}

int words_with_prefix(string prefix){
  node* current = head;
  for(unsigned int i=0;i<prefix.length();++i){
    if(current->child[((int)prefix[i] - (int)'a')] == NULL){
      return 0;
    }else{
      current = current->child[((int)prefix[i] - (int)'a')];
    }
  }
  return current->prefix_count;
}

void try_insert(){
  string word;
  cout << "Write a word: ";
  cin.ignore();
  getline(cin,word);
  insert(word);
}

void try_search(){
  string word;
  cout << "Write a word: ";
  cin.ignore();
  getline(cin,word);

  if(search(word)==true){
    cout << word << " has been found in the dictionary" << endl;
  }else{
    cout << word << " is not a word" << endl;
  }
}

void try_count(){
  string word;
  cout << "Write a prefix: ";
  cin.ignore();
  getline(cin,word);

  int num = words_with_prefix(word);
  cout << num << " words have been found with the \"" << word << "\" prefix" << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
  head = new node();
  head->prefix_count = 0;
  head->is_end = false;

  char input_line[100];
  char *result;
  int i=0,q;
  string code, line, hash;

  //<snip>

  		cin >> code;
			cin >> hash;

  while((result = fgets(input_line, 100, stdin )) != NULL){
    //si la longitud es más de 17, ni la cargues al trie.
    insert(result);
    ++i;
  }    



  cout << i << " lines read";
  cout << "Adios" << endl;

/*
  int option;
  while(1){
    cout << "Menu" << endl;
    cout << "1. Insert" << endl
         << "2. Search" << endl
         << "3. Count prefix" << endl
         << "4. Break" << endl;
    cin >> option;
    if(option==1){
      try_insert();
    }else if(option==2){
      try_search();
    }else if(option==3){
      try_count();
    }else if(option==4){
      break;
    }else{
      cout << "Repeat" << endl;
    }
  }
  */

	return 0;
}

