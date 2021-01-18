package main

import (
	"reflect"
	"testing"
)

func Test_fizzBuzz(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
		want []string
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		if got := fizzBuzz(tt.args.n); !reflect.DeepEqual(got, tt.want) {
			t.Errorf("%q. fizzBuzz() = %v, want %v", tt.name, got, tt.want)
		}
	}
}
