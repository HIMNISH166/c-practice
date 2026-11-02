int strStr(char* haystack, char* needle) {
    int h = strlen(haystack);
    int n = strlen(needle);
    int count = 0;

    if(h<n)return -1;

    for(int i=0;i<h;i++){
        if(haystack[i]==needle[0]){
            for(int j=0;haystack[i+j]!='\0' && j<n;j++){
                if(haystack[i+j]==needle[j]){
                    count++;
                }
            }

            if(count==n){
                return i;
            }else{
                count=0;
            }
        }
    }

    return -1;
}