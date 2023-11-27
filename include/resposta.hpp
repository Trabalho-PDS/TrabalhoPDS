#pragma once

#include <string>
#include <iostream>

class Resposta {
public:

  Resposta(std::string const& post_id, std::string const& id_monitor, std::string const& content);
  Resposta();

  public:
  std::string getPostId() const;
  std::string getIdMonitor() const;
  std::string getContent() const;
  std::string getAnswerId() const;

  void setPostId(std::string const& post_id);
  void setIdMonitor(std::string const& id_monitor);
  void setContent(std::string const& content);
  void setAnswerId(std::string const& answer_id);

private:
  std::string _post_id;
  std::string _id_monitor;
  std::string _content;
  std::string _titulo;
  std::string _answer_id;
};