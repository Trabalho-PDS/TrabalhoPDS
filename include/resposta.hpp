#pragma once

#include <string>
#include <iostream>

class Resposta {
public:
  /**
  * @brief Construtor padrão da classe Resposta.
  * @param post_id, id_monitor, content: post_id, id_monitor, content.
  * @retval none.
  * */
  Resposta(std::string const& post_id, std::string const& id_monitor, std::string const& content);
  /**
  * @brief Construtor genérico da classe Resposta.
  * @retval none.
  * */
  Resposta();

  public:
  /**
  * @brief Getter id do post.
  * @retval std::string
  * */
  //! 
  std::string getPostId() const;
  /**
  * @brief Getter id do monitor.
  * @retval std::string
  * */
  //! 
  std::string getIdMonitor() const;
  /**
  * @brief Getter conteudo da resposta.
  * @retval std::string
  * */
  //! 
  std::string getContent() const;
  /**
  * @brief Getter id da resposta.
  * @retval std::string
  * */
  std::string getAnswerId() const;
  /**
  * @brief Setter id do post.
  * @param post_id: id do post.
  * @retval none.
  * */
  void setPostId(std::string const& post_id);
  /**
  * @brief Setter id do monitor.
  * @param id_monitor: id do monitor.
  * @retval none.
  * */
  void setIdMonitor(std::string const& id_monitor);
  /**
  * @brief Setter conteudo da resposta
  * @param content: conteudo.
  * @retval none.
  * */
  void setContent(std::string const& content);
  /**
  * @brief Setter id da resposta.
  * @param answer_id: id da resposta.
  * @retval none.
  * */
  void setAnswerId(std::string const& answer_id);

private:
  std::string _post_id;
  std::string _id_monitor;
  std::string _content;
  std::string _titulo;
  std::string _answer_id;
};