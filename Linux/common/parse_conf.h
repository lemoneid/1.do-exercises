/*************************************************************************
	> File Name: ../common/parse_conf.h
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月18日 星期日 15时29分39秒
 ************************************************************************/

#ifndef _PARSE_CONF_H
#define _PARSE_CONF_H
int parse_conf(char *string);
int get_string(const char *file, char *buff, size_t size);
cJSON *get_cjson(const char *file);
int get_json_valueint(cJSON *conf, const char *who, const char *config);
char *get_json_valuestring(cJSON *conf, const char *who, const char *config);
int get_json_array_valueint(cJSON *conf, const char *who, const char *config, const char *shell);
#endif
