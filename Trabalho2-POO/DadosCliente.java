package Trabalho2;

import java.util.ArrayList;

public class DadosCliente {
	private ArrayList<Cliente> vetCliente = new ArrayList<Cliente>();
	
	public void cadastrar(Cliente c) {
		this.vetCliente.add(c);
		Persist.salvarBinario("clientes.dat", c);//Salvar no arquivo
		System.out.println("Total de clientes inseridos: ");
		System.out.println(this.vetCliente.size());
	}
	
	public void listar(){
		for (Cliente objeto: this.vetCliente) {
			objeto.mostarDados();
		}
	}
	
	public Cliente buscar(String nome) {
		Cliente c = null;
		for ( Cliente objeto: this.vetCliente) {
			if (objeto.getNome().equals(nome)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String nome){
		Cliente clienteRemove = this.buscar(nome);
		
		if(clienteRemove != null) {
			this.vetCliente.remove(clienteRemove);
			return true;
		}else {
			return false;
		}
	}
	
}
