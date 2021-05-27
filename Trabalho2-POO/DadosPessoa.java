package Trabalho2;

import java.util.ArrayList;

public class DadosPessoa {
	private ArrayList<Pessoa> vetPessoa = new ArrayList<Pessoa>();
	
	public void cadastrar(Pessoa c) {
		this.vetPessoa.add(c);
		Persist.salvarBinario("pesssoas.dat", c);//Salvar no arquivo
		System.out.println("Total de pessoas inseridas: ");
		System.out.println(this.vetPessoa.size());
	}
	
	public void listar(){
		for (Pessoa objeto: this.vetPessoa) {
			objeto.mostarDados();
		}
	}
	
	public Pessoa buscar(String nome) {
		Pessoa c = null;
		for ( Pessoa objeto: this.vetPessoa) {
			if (objeto.getNome().equals(nome)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String nome){
		Pessoa pessoaRemove = this.buscar(nome);
		
		if(pessoaRemove != null) {
			this.vetPessoa.remove(pessoaRemove);
			return true;
		}else {
			return false;
		}
	}
}
