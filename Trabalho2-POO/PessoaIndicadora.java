package Trabalho2;

public class PessoaIndicadora {
	private String nome;
	private String cpf;
	
	public PessoaIndicadora() {
		
	}
	public PessoaIndicadora(String nome, String cpf) {
		setNome(nome);
		setCpf(cpf);
	}
	
	public String getNome() {
		return nome;
	}
	public boolean setNome(String nome) {
		if(nome.length() > 0) {
			this.nome = nome;	
			return true;
		}else {
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
	
}
