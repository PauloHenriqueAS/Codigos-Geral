package Trabalho2;

import java.util.ArrayList;

public class DadosLogin {
	private ArrayList<Login> vetLogin = new ArrayList<Login>();
	
	public void cadastrar(Login c) {
		this.vetLogin.add(c);
		Persist.salvarBinario("login.dat", c);//Salvar no arquivo
		System.out.println("Total de logins inseridos: ");
		System.out.println(this.vetLogin.size());
	}
	
	public void listar(){
		for (Login objeto: this.vetLogin) {
			objeto.mostarDados();
		}
	}
	
	public Login buscar(String user) {
		Login c = null;
		for ( Login objeto: this.vetLogin) {
			if (objeto.getUsuario().equals(user)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String user){
		Login loginRemove = this.buscar(user);
		
		if(loginRemove != null) {
			this.vetLogin.remove(loginRemove);
			return true;
		}else {
			return false;
		}
	}
	
}
