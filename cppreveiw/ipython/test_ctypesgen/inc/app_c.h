#ifndef __APP_H__
#define __APP_H__
#ifdef __cplusplus
extern "C" 
{
#endif
    typedef struct App_c App_c;

    App_c * create_app();

    void run(App_c * app_ptr);
    void show(App_c * app_ptr);
    void add(App_c * app_ptr, int a, int b);

    void delete_app(App_c* app_ptr);
#ifdef __cplusplus
}
#endif

#endif