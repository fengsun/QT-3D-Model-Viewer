#include "scene.h"
#include "gameobject.h"
#include "component.h"
#include "transform.h"
#include "mesh.h"
#include "resources.h"

#include <QOpenGLBuffer>
#include <QOpenGLTexture>

Scene::Scene()
{
    root = new GameObject("root");
}

Scene::~Scene()
{
    Clear();
    delete root;
}

Mesh* Scene::InitDemo(MyOpenGLWidget* renderer)
{
    GameObject* go = AddGameObject("Demo Cube");
    Mesh* mesh = new Mesh(go);
    mesh->LoadFromFile("QtLogo", renderer);
    return mesh;
}

void Scene::Clear()
{
    delete root;
    root = new GameObject("root");
}

void Scene::Draw(MyOpenGLWidget* renderer)
{
    root->Draw(renderer);
}

GameObject *Scene::AddGameObject(QString name, GameObject *parent)
{
    if (parent == nullptr)
        parent = root;

    GameObject* ret = new GameObject(name, parent);
    parent->childs.push_back(ret);
    return ret;
}

void Scene::RemoveEntity(int id)
{

}