


void select(){

  int val, pos, ch;
  ListElem *temp;
  char yes='y';
  makeEmpty();
  //Make the list empty

  while(yes=='y'){ cout<<"Enter your choice:";
    cin>>ch;
    switch(ch){

    case 1: cout<<"Value:";
            cin>>val;
            cout<<"Position:";
            cin>>pos;
            Insert(val,pos);
            break;
    case 2: cout<<"Position:";
            cin>>pos;
            Delete(pos);
            break;
    case 3: cout<<"Number of items:"< break;
    case 4: temp=findmin(pfirst);
            if(temp!=NULL) cout<<"The min item:"<data<<endl;
            else cout<<"Not found\n";
            break;
    case 5: temp=findmax(pfirst);
            if(temp!=NULL) cout<<"The max item:"<data<<endl;
            else cout<<"Not found\n";
            break;
    case 6: cout<<"Find what:";
            cin>>val;
            temp=find(pfirst,val);
            if(temp!=NULL) cout<<"The found item:"<data<<endl;
            else cout<<"Not found\n";
            break;
    case 7: cout<<"All items:\n";
            printall(pfirst);
            break;
    case 8: exit(0);
    default: cout<<"Invalid choice\n";
    }
    cout<<"Continue?y/n:";
    cin>>yes;
  }
}
