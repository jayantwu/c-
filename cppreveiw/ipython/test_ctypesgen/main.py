import sys
sys.path.append('./build/lib/')
import app


def main():
    myapp = app.create_app()
    app.run(myapp)
    app.show(myapp)
    app.add(myapp, 3, 9)
    app.delete_app(myapp)

if __name__ == '__main__':
    main()
