#include<stdio.h>
#include <unistd.h>
#include<string.h>

void create_dir(char* project_name) {
    char cwd[150];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
    mkdir(project_name);

    // creating kalki.py file with contents
    char *cwd_path = strcat(cwd, "/");
    char * kalkipath = strcat(cwd, project_name);
    char * kalkipy_path = strcat(kalkipath, "/manage.py");
    printf("%s\n", kalkipy_path);
    printf("%s", kalkipath);

    FILE *kalki;

    kalki = fopen(kalkipy_path, "w");
    char * content = "import sys\ntry:\n\timport settings\nexcept:\n\tpass\ntry:\n\tfrom kalki import kalkiminify\nexcept:\n\tpass\ntry:\n\tfrom kalki import service\nexcept:\n\tpass\ntry:\n\tfrom kalki import create_app\nexcept:\n\tpass\n\ntry:\n\tappname = sys.argv[2]\nexcept:\n\tprint('provide a appname')\n\ndef check_appname():\n\tfor app in settings.APP_NAME:\n\t\tif app == appname:\n\t\t\treturn True\n\ndef startapp():\n\tcreate_app.startapp(appname)\n\ndef compile():\n\tif check_appname():\n\t\tservice.service(appname)\n\telse:\n\t\tprint('Appname do not exists.')\n\t\tprint(\"If the app exists, add the app to APP_NAME in settings.py\")\n\ndef minify():\n\tif check_appname():\n\t\tkalkiminify.kalkiminify(appname)\n\telse:\n\t\tprint('Appname do not exists.')\n\t\tprint(\"If the app exists, add the app to APP_NAME in settings.py\")\n\nif __name__ == '__main__':\n\ttry:\n\t\tglobals()[sys.argv[1]]()\n\texcept IndexError:\n\t\tprint(\"\"\"\n\t\t\tavailable commands-\n\t\t\t\tstartapp\n\t\t\t\tcompile\n\t\t\t\tminify\n\t\t\tUse these commands like-\n\t\t\t\t'python kalki.py startapp' to create working directory\n\t\t\t\t'python kalki.py compile' to create compiled css file\n\t\t\t\t'python kalki.py minify' to create minified css file\n\t\t\t\"\"\")";
    fputs(content,kalki);
    fclose(kalki);
}