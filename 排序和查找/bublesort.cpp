void bublesort(){
    //冒泡排序算法的优化
    //每次把本次最大的元素放到最后
    bool update=true;
    for(int i=0;update&&i<n-1;i++){
        update=false;
        //如果没有更新发生，说明数组已经有序
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                update=true;
                swaper(j,j+1);
            }
        }
    }
}