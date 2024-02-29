#include <initializer_list>
#include <vector>

class IScreen{};    // абстрактный класс - экран(область для рисования)
class Console : public IScreen{};
class Window  : public IScreen{};

struct point_t  {};
struct matrix_t {};
struct vector_t {};

class AfineTransform{};

// Интерфейс. Отвечает за отрисовку и то как мы видим фигуру
class IShape{
public:
    virtual void draw() = 0;
    virtual void drawOnScreen(IScreen *screen) = 0;
};

// Интерфейс. Отвечает за геометрию фигуры(т.ч преобразования)
class IGeometryShape{
public:
    virtual void translate(const vector_t &vector) = 0; // параллельный перенос геометрической фигуры
    virtual void rotate   (const matrix_t &matr)   = 0; // вращение
    virtual void scale    (double s)               = 0; // масштабирование

    virtual void transform(const matrix_t & matr)  = 0; // какое то другое линейное преобразование
};

// Polygon это класс, реализующий понятие многоугольника на плоскости
class Polygon : public IShape, public IGeometryShape{   
public:
    explicit Polygon(std::initializer_list<point_t> vertices);
    explicit Polygon(std::initializer_list<Polygon> polygons);

    Polygon();
    //... другие варианты конструкторов(копирования, перемещения)

    // Движение полигона
    void translate(const vector_t &vector) override; // параллельный перенос полигона
    void rotate   (const matrix_t & matr)  override; // вращение полигона
    void scale    (double s)               override; // масштабирование полинона

    void transform(const matrix_t &matr)   override;  // какое то другое линейное преобразование
    //...
    // другие возможные геометрически преобразования полигона

    // метод рисования можно переопределить.
    virtual void draw() override;

private:
    void findConvexShape(std::vector<point_t> &convShape); // находим выпуклую оболочку нашего полигона
    void polygonShape();                                   // разбиваем наш полигон

private:
    std::vector<point_t> convexVerices; // выпуклая оболочка нашего полигона(многоугольника)
    std::vector<point_t> vetices;       // все вершины
    std::vector<Polygon> polygons;      // наш полигон может состоять из других полигонов
};

class Triangle : public Polygon{
public:

    explicit Triangle(std::initializer_list<point_t> v): Polygon(v) {};
    void draw() override;
};

class Quad : public Polygon{
public:

    explicit Quad(std::initializer_list<point_t> v): Polygon(v) {};
    void draw() override;
};

class Circle : public IShape, public IGeometryShape{
public:

    Circle(point_t center, double radius);

    void translate(const vector_t &vector)override; // параллельный перенос
    void rotate   (const matrix_t & matr) override; // вращение
    void scale    (double s)              override; // масштабирование

    void draw() override;
};
