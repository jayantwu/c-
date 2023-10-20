// #include "inc/app.h"
#include "inc/app_c.h"


int main() {
    App_c * appptr = create_app();

    run(appptr);
    delete_app(appptr);

    return 0;
}