namespace WorldBuilder.Entities
{
    public abstract class Resource
    {
        public string Name { get; }
        protected Resource(string name)
        {
            Name = name;
        }
    }

    public class TechResource : Resource
    {
        public TechResource(string name) : base(name) {}
    }

    public class HumanSkill : Resource
    {
        public HumanSkill(string name) : base(name) {}
    }
}
