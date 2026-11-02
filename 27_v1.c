#define INF 51

int comp(const void* a,const void* b){
    int x= *(const int*)a;
    int y= *(const int*)b;

    if(x-y>0)return 1;
    if(x-y<0)return -1;
    return 0;
}

int removeElement(int* nums, int numsSize, int val) {

int k=0;

for(int i=0;i<numsSize;i++){
    if(nums[i]==val){
        nums[i]=INF;
        k++;
    }
}

    qsort(nums,numsSize,sizeof(nums[0]),comp);

    return numsSize-k;
}