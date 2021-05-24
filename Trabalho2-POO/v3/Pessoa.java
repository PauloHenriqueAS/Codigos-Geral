package Trabalho2;

public class Pessoa {
	protected String nome;
	protected String cpf;
	protected String email;
	protected String sexo;
	
	public Pessoa () {
		
	}
	public Pessoa (String nome, String cpf, String email, String sexo) {
		setNome(nome);
		setCpf(cpf);
		setEmail(email);
		setSexo(sexo);
	}

	public String getNome() {
		return nome;
	}
	public boolean setNome(String nome) {
		if(nome.length() > 0) {
			this.nome = nome;
			return true;
		}else{
			return false;
		}
	}
	public String getCpf() {
		return cpf;
	}
	public boolean setCpf(String cpf) {
		if(cpf.length() > 0) {
			this.cpf = cpf;
			return true;
		}else {
			return false;
		}
	}
	public String getEmail() {
		return email;
	}
	public boolean setEmail(String email) {
		if(email.length() > 0) {
			this.email = email;
			return true;
		}else {
			return false;
		}
	}
	public String getSexo() {
		return sexo;
	}
	public boolean setSexo(String sexo) {
		if(sexo.length() > 0) {
			this.sexo = sexo;
			return true;
		}else {
			return false;
		}
	}
	
	public void mostarDados(){
		System.out.println("Pessoa: " + getNome());
		System.out.println("CPF: " + getCpf());
		System.out.println("Email: " + getEmail());
		System.out.println("Sexo: " + getSexo());
	}
	/*Metodos
	public	ArrayList<String> consultarCPF(String cpfConsulta){
		return this.cpf;
	}*/
}
