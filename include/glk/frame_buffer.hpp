#ifndef GLK_FRAME_BUFFER_HPP
#define GLK_FRAME_BUFFER_HPP

#include <memory>
#include <GL/gl3w.h>
#include <Eigen/Core>

#include <glk/texture.hpp>

namespace glk {

class FrameBuffer {
public:
  FrameBuffer(const Eigen::Vector2i& size, int num_color_buffers = 1, bool use_depth = true);

  ~FrameBuffer();

  void bind();
  void unbind() const;

  int num_color_buffers() const;
  void add_color_buffer(int layout, GLuint internal_format, GLuint format, GLuint type);

  Eigen::Vector2i size() const;
  void set_size(const Eigen::Vector2i& size);

  const Texture& color() const;
  const Texture& color(int i) const;
  const Texture& depth() const;

private:
  int width;
  int height;

  GLint viewport[4];

  std::vector<GLenum> color_attachments;
  std::vector<std::shared_ptr<Texture>> color_buffers;
  std::shared_ptr<Texture> depth_buffer;

  GLuint frame_buffer;
};

}  // namespace glk

#endif