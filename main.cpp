#include<iostream>
using namespace std;
typedef struct T
{
    int value,distance;
    int  index_left_child  = -1 ;
    int  index_right_child = -1 ;
    int farthest_child = 0 ;
    int index_father = 0  ;
} Node;
Node * maxNode(Node*a,Node*b)
{
    if (a->farthest_child > b->farthest_child)
        return a;
    if (a->farthest_child < b->farthest_child)
        return b;
    if (a->farthest_child == b->farthest_child)
        return a;
}
bool isLeaf(Node*a)
{
    return ( a->index_left_child == -1 && a->index_right_child == -1 ) ;
}
int counter = 0 ;
Node* re_Farthest_Node(Node *arr[], int i )
{
    if (isLeaf(arr[i]) && arr[i]->distance > arr[arr[i]->index_father]->distance)
    {
        arr[i]->farthest_child = counter ;
        return arr[i];
    }
    if (arr[i]->index_left_child != -1 && arr[i]->index_right_child != -1)
    {
        counter++;
        int temp = counter;
        Node* t1 = new Node;
        Node* t2 = new Node;
        t1 = re_Farthest_Node(arr,arr[i]->index_left_child);
        counter = temp ;
        t2 = re_Farthest_Node(arr,arr[i]->index_right_child);
        return maxNode(t1,t2);
    }
    if (arr[i]->index_left_child != -1 && arr[i]->index_right_child == -1)
    {
        counter++;
        return re_Farthest_Node(arr,arr[i]->index_left_child);
    }
    if (arr[i]->index_left_child == -1 && arr[i]->index_right_child != -1)
    {
        counter++;
        return re_Farthest_Node(arr,arr[i]->index_right_child);
    }
}
int num = 0 ;
int main()
{
    int n,x,y;
    cin>>n;
    int w = n ;
    Node *arr[n] ;
    arr[1] = new Node;
    arr[1]->value = 1 ;
    arr[1]->distance = 0 ;
    int i = 2 ;
    int q = 1 ;
    while ( n > 0 )
    {
        cin>>x>>y;
        if ( x != -1 && y != -1 )
        {
            Node *node1 = new Node;
            node1->value = x ;
            node1->distance = arr[q]->distance + 1 ;
            node1->index_father = q ;
            arr[i] = node1 ;
            arr[q]->index_left_child = i;
            i++;
            Node* node2 = new Node;
            node2->value = y;
            node2->distance = arr[q]->distance + 1 ;
            node2->index_father = q ;
            arr[i] = node2 ;
            arr[q]->index_right_child = i;
            q++;
            i++;
            n--;
        }
        if ( x != -1 && y == -1 )
        {
            Node *node1 = new Node;
            node1->value = x ;
            node1->distance = arr[q]->distance + 1 ;
            node1->index_father = q ;
            arr[i] = node1 ;
            arr[q]->index_left_child = i;
            q++;
            i++;
            n--;
        }
        if (( x == -1 && y != -1 ))
        {
            Node* node2 = new Node;
            node2->value = y;
            node2->distance = arr[q]->distance + 1 ;
            node2->index_father = q ;
            arr[i] = node2 ;
            arr[q]->index_right_child = i;
            q++;
            i++;
            n--;
        }
        if (x == -1 && y == -1 )
        {
            q++;
            n--;
        }
    }
    cout<<endl<<endl;
    Node* temp_node = new Node;
    for (int i = 1 ; i <= w ; i++)
    {
        counter = 0 ;
        temp_node = re_Farthest_Node(arr,arr[i]->value);
        cout<<temp_node->value<<" "<<temp_node->farthest_child<<"\n";
    }
    return 0;
}
