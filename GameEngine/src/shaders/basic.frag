#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 colour;
uniform vec2 light_pos;

in DATA
{
	vec4 position;
	vec2 uv;
	float tid;
	vec4 color;
} fs_in;

uniform sampler2D tex;
uniform sampler2D textures[32];

void main()
{
	float intensity = 1.0 / length(fs_in.position.xy - light_pos);
	//color = fs_in.color * intensity;
	vec4 texColor = fs_in.color;
	if (fs_in.tid > 0.0)
	{
		int tid = int(fs_in.tid - 0.5);
		if(tid == 1){
			texColor = texture(textures[0], fs_in.uv);
		}

		if(tid == 2){
			texColor = texture(textures[1], fs_in.uv);
		}

		if(tid == 3){
			texColor = texture(textures[2], fs_in.uv);
		}
	}

	color = texColor * intensity;
}