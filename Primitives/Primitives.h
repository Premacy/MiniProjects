#include <initializer_list>
#include <vector>

class IScreen{};    // абстрактный класс - экран(область для рисования)
class Console : public IScreen{};
class Window  : public IScreen{};

struct point_t  {};
struct matrix_t {};
struct vector_t {};

class AffineTransform{};

// Интерфейс. Отвечает за отрисовку и то как мы видим фигуру
class IDrawingShape{
public:
    virtual void draw() = 0;
    virtual void drawOnScreen(IScreen *screen) = 0;

    virtual ~IDrawingShape() = 0;
};

// Интерфейс. Отвечает за геометрию фигуры(т.ч преобразования)
class IGeometryShape{
public:
    virtual void translate(const vector_t &vector) = 0; 
    virtual void rotate   (const matrix_t &matrix) = 0; 
    virtual void scale    (double s)               = 0; 

    virtual void transform(const matrix_t & matrix) = 0; 
};

// Polygon это класс, реализующий понятие многоугольника на плоскости
class Polygon : public IDrawingShape, public IGeometryShape{   
public:
    explicit Polygon(std::initializer_list<point_t> vertices);
    explicit Polygon(std::initializer_list<Polygon> polygons);

    Polygon();
    //... другие варианты конструкторов(копирования, перемещения)

    // Движения полигона
    void translate(const vector_t &vector)  override; 
    void rotate   (const matrix_t & matrix) override; 
    void scale    (double s)                override; 

    void transform(const matrix_t &matrix)  override;  

    virtual void draw() override;

private:
    void findConvexShape(std::vector<point_t> &convShape);

private:
    std::vector<int> convexVerices;      // выпуклая оболочка нашего полигона(многоугольника)
    std::vector<point_t> vetices;       // все вершины
    std::vector<Polygon> polygons;      // наш полигон может состоять из других полигонов
};

class Triangle : public Polygon{
public:
    explicit Triangle(std::initializer_list<point_t> v): Polygon(v) {};
    void draw() override
};

class Quad : public Polygon{
public:
    explicit Quad(std::initializer_list<point_t> v): Polygon(v) {};
    void draw() override;
};

class Circle : public IDrawingShape, public IGeometryShape{
public:

    Circle(point_t center, double radius);

    void translate(const vector_t &vector) override; 
    void rotate   (const matrix_t &matrix) override; 
    void scale    (double s)               override; 

    void draw() override;
};
