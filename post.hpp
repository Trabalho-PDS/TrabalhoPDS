class Post {
public:
  
  Post(std::string disciplina,std::username, std::string conteudo, std::string titulo, unsigned user_id, unsigned post_id);

private:
  std::string _disciplina;
  std::string _conteudo;
  std::string _titulo;
  std::string _username;
  unsigned _user_id;
  unsigned _post_id;
}