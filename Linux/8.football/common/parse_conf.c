/*************************************************************************
	> File Name: ../common/parse_conf.c
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月18日 星期日 15时30分29秒
 ************************************************************************/
#include "head.h"

cJSON *get_cjson(const char *file) {
    cJSON *conf = NULL;
    int status = 0;
    if ((conf = cJSON_Parse(file)) == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            status = -1;
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
    }
    return conf;
}
int get_json_valueint(cJSON *conf, const char *config) {
    cJSON *ret = NULL;
    ret = cJSON_GetObjectItemCaseSensitive(conf, config);
    return ret->valueint;
}
char *get_json_valuestring(cJSON *conf, const char *config) {
    cJSON *ret = NULL;
    ret = cJSON_GetObjectItemCaseSensitive(conf, config);
    return ret->valuestring;
}
int get_json_array_valueint(cJSON *conf, const char *who, const char *config, const char *shell) {
    const cJSON *host = NULL;
    const cJSON *ConfigJson = NULL;
    cJSON *ret = NULL;
    host =  cJSON_GetObjectItemCaseSensitive(conf, who);
    ConfigJson = cJSON_GetObjectItemCaseSensitive(host, config);
    ret = cJSON_GetObjectItemCaseSensitive(ConfigJson, shell);
    return ret->valueint; 
}

int parse_conf(char *string) {
    const cJSON *master = NULL;
    const cJSON *slave = NULL;
    cJSON *conf = NULL;
    int status = 0;
    if ((conf = cJSON_Parse(string)) == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            status = -1;
            fprintf(stderr, "Error before: %s\n", error_ptr);
            goto end;
        }
    }
    master =  cJSON_GetObjectItemCaseSensitive(conf, "Master");
    slave =  cJSON_GetObjectItemCaseSensitive(conf, "Slave");

    cJSON *master_port = cJSON_GetObjectItemCaseSensitive(master, "MasterPort");
    cJSON *slave_port = cJSON_GetObjectItemCaseSensitive(slave, "SlavePort");
    printf("MasterPort = %d, SlavePort = %d\n", master_port->valueint, slave_port->valueint);

    end:
    cJSON_Delete(conf);
    return status;
}

int get_string(const char *pathname, char *buff, size_t size) {
    FILE *file = NULL;
    size_t len;
    if ((file = fopen(pathname, "rb")) == NULL) {
                perror("fopen()");
                exit(1);
    }
    fseek(file, 0L, SEEK_END);
    len = ftell(file);
    fseek(file, 0L, SEEK_SET);
    if (len > size) {
        fprintf(stderr, "Buffer is less than len of file!\n");
        return -1;
    }
    fread(buff, len, 1, file);
    fclose(file);
    return len;
}
