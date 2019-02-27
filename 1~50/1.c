// 以下头文件已引入
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stddef.h>
// #include <ctype.h>

/**
 * @param  char*  单行测试数据
 */
void solution(char *line)
{
    // 在此处理单行测试数据
        // 在此处理单行测试数据
    int a, b;
    sscanf(line, "%d%d", &a, &b);
    printf("%d\n", a + b);
    // 打印处理结果，务必输出换行符
    // printf("%s\n", result);
}