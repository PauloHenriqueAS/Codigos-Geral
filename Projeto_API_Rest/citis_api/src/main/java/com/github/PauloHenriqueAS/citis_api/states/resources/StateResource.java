package com.github.PauloHenriqueAS.citis_api.states.resources;

import com.github.PauloHenriqueAS.citis_api.states.State;
import com.github.PauloHenriqueAS.citis_api.states.repository.StateRepository;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
@RestController
@RequestMapping("/states")

public class StateResource {

        private final StateRepository repository;

        public StateResource(final StateRepository repository) {
            this.repository = repository;
        }

        @GetMapping
        public List<State> staties() {
            return repository.findAll();
        }
}
