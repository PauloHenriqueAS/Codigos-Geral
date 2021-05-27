package Trabalho2;

import java.util.ArrayList;

public class DadosUsuario {
	private ArrayList<Usuario> vetUser = new ArrayList<Usuario>();
	
	public void cadastrar(Usuario user) {
		this.vetUser.add(user);
		Persist.salvarBinario("usuarios.dat", user);//Salvar no arquivo
		System.out.println("Total de usuarios inseridos: ");
		System.out.println(this.vetUser.size());
	}
	
	public void listar(){
		for (Usuario objeto: this.vetUser) {
			objeto.mostarDados();
		}
	}
	
	public Usuario buscar(String nome) {
		Usuario c = null;
		for ( Usuario objeto: this.vetUser) {
			if (objeto.getNome().equals(nome)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String nome){
		Usuario userRemove = this.buscar(nome);
		
		if(userRemove != null) {
			this.vetUser.remove(userRemove);
			return true;
		}else {
			return false;
		}
	}
	
}
