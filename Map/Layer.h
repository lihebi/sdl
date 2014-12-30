#ifndef __LAYER_H__
#define __LAYER_H__

class Layer
{
public:

  virtual void render() = 0;
  virtual void update() = 0;

protected:

  virtual ~Layer() {}

private:
  /* data */
};

#endif /* end of include guard: __LAYER_H__ */
