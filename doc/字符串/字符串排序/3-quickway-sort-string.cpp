int charat(string s,int index){
    if(index>=s.size())return -1;
    else return s[index];
}

void sort(int lo,int hi,int d){
    if(lo>=hi)return;
    int v=charat(a[lo],d);
    int i=lo+1;
    int lt=lo;
    int gt=hi;
    while(i<=gt){
        int tmp=charat(a[i],d);
        if(tmp>v) std::swap(a[i],a[gt--]);
        else if(tmp<v) std::swap(a[i++],a[lt++]);
        else i++;
    }
    //a[lo..lt-1]<v=a[lt...gt]<a[gt+1...hi]
    if(v>=0)sort(lt,gt,d+1);
    sort(lo,lt-1,d);
    sort(gt+1,hi,d);
}