## 选择排序

交换次数最少的排序方式。

但是无论是最好还是最坏算法复杂度都是 ==O(n^2)

```
for(int i=0; i<v.size(); i++){
                int min = v[i]; 
                int temp;
                int index = i;
                for(int j=i+1;j<v.size();j++){
                    if(v[j] < min){ 
                        min = v[j]; 
                        index = j;
                    }       
                }       
        
                temp = v[i]; 
                v[i] = min;
                v[index]= temp;
        }

```