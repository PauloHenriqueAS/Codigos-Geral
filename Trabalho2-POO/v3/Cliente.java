package Trabalho2;

public class Cliente extends Pessoa{
	protected String profissao;
	protected String estadoCivil;
	
	public Cliente () {	}
	
	public Cliente (String nome, String cpf, String email, String sexo, String prof, String estadoC) {
		super(nome, cpf, email, sexo);
		setProfissao(prof);
		setEstadoCivil(estadoC);
	}
	
	public String getProfissao() {
		return profissao;
	}
	public boolean setProfissao(String profissao) {
		if(profissao.length() > 0) {
			this.profissao = profissao;
			return true;
		}else {
			return false;
		}
	}
	public String getEstadoCivil() {
		return estadoCivil;
	}
	public boolean setEstadoCivil(String estadoCivil) {
		if(estadoCivil.length() > 0) {
			this.estadoCivil = estadoCivil;
			return true;
		}else {
			return false;
		}
	}
	
	public void mostarDados(){
		System.out.println("Profissao: " + getProfissao());
		System.out.println("Estado Civil: " + getEstadoCivil());
	}
					/*Metodo
	public ArrayList<String> pesquisarPorRegistro(String registro){	}
	public ArrayList<String> pesquisarPorProprietario(String cpfProprietario){}
	public void cadastrarCliente(String nome, String cpf, String email, String sexo, String prof, String estadoCivil, LocalDate dataPrimCadastro){}
	*/
}
