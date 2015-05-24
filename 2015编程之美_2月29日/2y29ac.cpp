#include <cstdio>
#include <cstring>
int main()
{
    char start_month[12], end_month[12];
    int start_day, start_year, end_day, end_year;
    int T, count;
    while(scanf("%d", &T)!=EOF)
    {
        for(int i=1; i<=T; ++i)
        {
            scanf("%s %d, %d", start_month, &start_day, &start_year);
            scanf("%s %d, %d", end_month, &end_day, &end_year);
            count = 0;
            if(strcmp(start_month,"January")==0 || (strcmp(start_month,"February")==0&&start_day<=29))
            {
                --start_year;
            }
            if(strcmp(end_month,"January")==0 || (strcmp(end_month,"February")==0&&end_day<29))
            {
                --end_year;
            }
            count = (end_year>>2)-(start_year>>2);
            count = count -(end_year/100-start_year/100);
            count += ((end_year/400-start_year/400));
            printf("Case #%d: %d\n", i, count);
        }
    }
    return 0;
}
