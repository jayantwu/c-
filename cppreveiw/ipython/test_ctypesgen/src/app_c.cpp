#include "../inc/app_c.h"
#include "../inc/app.h"
#include <cstdlib>
#include <stdio.h>

extern "C" {
struct App_c {
     App app;
};

App_c* create_app()
{
    return new App_c();
}

void run(App_c * app_ptr)
{
    app_ptr->app.run();
}
void show(App_c * app_ptr)
{
    app_ptr->app.show();
}
void add(App_c * app_ptr, int a, int b)
{
    app_ptr->app.add(a, b);
}

void delete_app(App_c* app_ptr)
{
    delete app_ptr;
    printf("delete app success.\n");
}

}
